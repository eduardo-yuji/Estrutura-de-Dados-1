#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

typedef struct{
    int ra;
    char nome[50];
} Aluno;

typedef struct{
    Aluno aluno[N];
    int topo;
} PilhaEstatica;



bool estaCheia(PilhaEstatica *p){
    if(p->topo == N) return true;
    return false;
}

void iniciaPilha(PilhaEstatica *p){
    p->topo = 0;
}

void inserirElemento(PilhaEstatica *p, Aluno elemento){
    if(estaCheia(p) == true){
        printf("Pilha Cheia. Impossivel inserir na pilha.\n");
        return;
    }else{
        p->aluno[p->topo] = elemento;
        p->topo++;
        //printf("Inserido com sucesso\n");
    }
}

int main(){
    PilhaEstatica pilha;
    Aluno elemento = {123, "Yuji"};
    iniciaPilha(&pilha);
    inserirElemento(&pilha, elemento);
    for(int i = 0; i< pilha.topo; i++){
        printf("Aluno[%d]: %s\nRA: %d\n\n", i, pilha.aluno[i].nome, pilha.aluno[i].ra);
    }
    return 0;
}