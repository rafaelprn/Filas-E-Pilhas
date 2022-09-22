#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *prox;
}Fila;

Fila *alocaNo(int k);
void removeItem(Fila **p);
void insereItem(Fila **p, int k);
int Vazia(Fila *p);
void LiberaFila(Fila **p);
void imprime(Fila *p);

int main(){
    
    return 0;
}

//FUNÇÕES
Fila *alocaNo(int k){
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    if(novo == NULL){
        return NULL;
    }
    novo->chave = k;
    novo->prox = NULL;
    return novo;
}

void removeItem(Fila **p){ //remoção de item na fila, remove o primeiro item
    if(*p == NULL){
        printf("Fila vazia!\n");
        return;
    }
    Fila *aux = *p; //vamos usar aux para remover
    *p = (*p)->prox; //faz p olhar para o segundo item pq vamos remover o primeiro
    free(aux);
}

void insereItem(Fila **p, int k){//inserção de item na fila, adiciona no fim da fila
    if(*p == NULL){
        printf("Fila vazia!\n");
        return;
    }
    Fila *aux = *p, *novo = alocaNo(k); //aux percorre, novo aloca
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}

int Vazia(Fila *p){//verifica se a fila esta vazia
    if(p != NULL){//se nao esta vazia
        printf("Nao esta vazia");
        return 0;
    }
    printf("A Fila esta vazia!");
    return 1;
}

void LiberaFila(Fila **p){
     if (*p == NULL){
        return;
    }
    LiberaFila(&(*p)->prox);
    (*p)->prox = NULL;
    free(*p);
    *p = NULL;
}

void imprime(Fila *p){
    if(p == NULL){
        printf("A Fila esta vazia!");
        return;
    }
    while(p != NULL){
        printf("\n%d", p->chave);
        p = p->prox;
    }
}

