#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *prox;
}Pilha;

Pilha *alocaNo(int k);
void removeItem(Pilha **p);
void insereItem(Pilha **p, int k);
int Vazia(Pilha *p);
void LiberaPilha(Pilha **p);
void imprime(Pilha *p);

int main(){

    return 0;
}

//FUNÇÕES
Pilha *alocaNo(int k){
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL){
        return NULL;
    }
    novo->chave = k;
    novo->prox = NULL;
    return novo;
}

void removeItem(Pilha **p){ //remoção de item na Pilha, remove o primeiro item
    if(*p == NULL){
        printf("Pilha vazia!\n");
        return;
    }
    Pilha *aux = *p; //vamos usar aux para remover
    *p = (*p)->prox; //faz p olhar para o segundo item pq vamos remover o primeiro
    free(aux);
}

void insereItem(Pilha **p, int k){//inserção de item na Pilha, adiciona no inicio (topo) da Pilha
    if(*p == NULL){
        printf("Pilha vazia!\n");
        return;
    }
    Pilha *aux = *p, *novo = alocaNo(k); //aux percorre, novo aloca
    novo->prox = *p;
    *p = novo;
}

int Vazia(Pilha *p){//verifica se a lista esta vazia
    if(p != NULL){//se nao esta vazia
        printf("Nao esta vazia");
        return 0;
    }
    printf("A Pilha esta vazia!");
    return 1;
}

void LiberaPilha(Pilha **p){
     if (*p == NULL){
        return;
    }
    LiberaPilha(&(*p)->prox);
    (*p)->prox = NULL;
    free(*p);
    *p = NULL;
}

void imprime(Pilha *p){
    if(p == NULL){
        printf("A Pilha esta vazia!");
        return;
    }
    while(p != NULL){
        printf("\n%d", p->chave);
        p = p->prox;
    }
}

