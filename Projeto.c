//Centro Universitário FEI
//CCA230 - Estrutura de dados e análise de algoritmos
//7° Ciclo - 2°Semestre 2021
//Professor: Danilo H. Perico
//Aluno: Ricardo H. A. Matheus
//RA: 15.118.334-0
//Projeto: Pilha Dinâmica - Torre de Hanoi
//link video: https://youtu.be/26ANlKf8HUs

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//Criação das estruturas:
struct Noh{
    int dado;
    struct Noh *proximo;
};

struct Lista{
    struct Noh *head;
    struct Noh *tail;
    int tamanho;
};

//Função que inicializa listas:
void inicializa(struct Lista *lst){
    lst->head = NULL;
    lst->tail = NULL;
    lst->tamanho = 0;
}

//Função push: Adiciona novos elementos no topo da pilha
void push(struct Lista *lst, int valor){
    struct Noh *noh_novo = malloc(sizeof(struct Noh));
    noh_novo->dado = valor;
    noh_novo->proximo = NULL;
    if(lst->tamanho == 0){
        lst->head = noh_novo;   
    }
    else{
        noh_novo->proximo = lst->head;
        lst->head = noh_novo;
    }
    lst->tamanho++;
}

//Função pop: Exclui o elemento do topo da pilha
void pop(struct Lista *lst){
    if(lst->tamanho == 0)
        puts("Lista vazia!"); 
    else{
        struct Noh *aux = lst->head;
        lst->head = aux->proximo;
        free(aux);
        lst->tamanho--;
    }
}

//Função display: Copia o estado atual da torre no console
void display(struct Lista *lst, struct Lista *lst2, struct Lista *lst3,int n){
    struct Noh *auxiliar = lst->head;
    struct Noh *auxiliar2 = lst2->head;
    struct Noh *auxiliar3 = lst3->head;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t |\t\t\t\t |\t\t\t\t |\n");
    while(auxiliar != NULL || auxiliar2 != NULL || auxiliar3 != NULL){
        if (lst->tamanho >=  n){
            if(auxiliar->dado < 10)
                printf("\t\t\t=%d=\t\t\t\t", auxiliar->dado);
            else
                printf("\t\t\t=%d=\t\t\t", auxiliar->dado);
            auxiliar = auxiliar->proximo;
        }
        else{
            printf("\t\t\t |\t\t\t\t");
        }
        if (lst2->tamanho >=  n){
            if(auxiliar2->dado < 10)
                printf("=%d=\t\t\t\t", auxiliar2->dado);
            else
                printf("=%d=\t\t\t", auxiliar2->dado);
            auxiliar2 = auxiliar2->proximo;
        }
        else{
            printf(" |\t\t\t\t");
        }
        if (lst3->tamanho >=  n){
            printf("=%d=\n", auxiliar3->dado);
            auxiliar3 = auxiliar3->proximo;
        }
        else{
            printf(" |\n");
        }
        n = n - 1;
    }
    puts("\n----------------------------------------------------------------------------------------------------------------------------\n");
    free(auxiliar);
    free(auxiliar2);
    free(auxiliar3);
}

int main(){
    //definição das variaveis.
    int n, mov, p;
    struct Lista pilha1;
    struct Lista pilha2;
    struct Lista pilha3;
    
    //inicialização das pilhas.
    inicializa(&pilha1);
    inicializa(&pilha2);
    inicializa(&pilha3);

    puts("\n\t\tPROJETO TORRE DE HANÓI\n\n");
    puts("Digite o numero de discos da torre:");
    scanf(" %d", &n);
    
    // p : variavel auxiliar que salva o valor de n.
    p = n;
    // mov : número de movimentos necessários para solução de uma torre com n discos.
    mov = pow(2,n) - 1;

    //cria uma pilha de valores decrescentes com n discos.
    while (n > 0){
        push(&pilha1, n);
        n = n - 1;
    }
    puts("\n");
    display(&pilha1, &pilha2, &pilha3, p);

    //Solução do jogo
    for(int i = 1; i <= mov; i++){
        sleep(1);
        //Movimento válido do disco superior entre o pino de origem e o pino de destino   
        if(i%3 == 1){
            if(pilha1.tamanho == 0){
                push(&pilha1,pilha3.head->dado);
                pop(&pilha3);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else if(pilha3.tamanho == 0){
                push(&pilha3,pilha1.head->dado);
                pop(&pilha1);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else if(pilha1.head->dado < pilha3.head->dado){
                push(&pilha3,pilha1.head->dado);
                pop(&pilha1);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else{
                push(&pilha1,pilha3.head->dado);
                pop(&pilha3);
                display(&pilha1, &pilha2, &pilha3, p);
            }
        }
        //Movimento válido do disco superior entre o pino de origem e o pino auxiliar
        if(i%3 == 2){
            if(pilha1.tamanho == 0){
                push(&pilha1,pilha2.head->dado);
                pop(&pilha2);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else if(pilha2.tamanho == 0){
                push(&pilha2,pilha1.head->dado);
                pop(&pilha1);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else if(pilha1.head->dado < pilha2.head->dado){
                push(&pilha2,pilha1.head->dado);
                pop(&pilha1);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else{
                push(&pilha1,pilha2.head->dado);
                pop(&pilha2);
                display(&pilha1, &pilha2, &pilha3, p);
            }
        }
        //Movimento válido do disco superior entre o pino auxiliar e o pino de destino
        if(i%3 == 0){
            if(pilha2.tamanho == 0){
                push(&pilha2,pilha3.head->dado);
                pop(&pilha3);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else if(pilha3.tamanho == 0){
                push(&pilha3,pilha2.head->dado);
                pop(&pilha2);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            if(pilha2.head->dado < pilha3.head->dado){
                push(&pilha3,pilha2.head->dado);
                pop(&pilha2);
                display(&pilha1, &pilha2, &pilha3, p);
            }
            else{
                push(&pilha2,pilha3.head->dado);
                pop(&pilha3);
                display(&pilha1, &pilha2, &pilha3, p);
            }
        }
    }
    puts("\t\t\t\t\t\t\tFIM.\n");
    return 0;
}