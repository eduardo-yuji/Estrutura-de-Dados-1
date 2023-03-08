#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 8

typedef struct Objeto{
    int chave;
} Objeto;

typedef struct FilaEstatica{
    Objeto fila[N];
    int inicio;
    int fim;
    int qtdElem;
}FilaEstatica;

void iniciaFila(FilaEstatica *f){
    f->inicio = -1;
    f->fim = -1;
    f->qtdElem = 0; 
}

bool estaVazia(FilaEstatica f){
    return(f.qtdElem == 0);
}

bool estaCheio(FilaEstatica f){
    return(f.qtdElem == N);
}

void inserirFila(FilaEstatica *f, int aux){
    if(f->qtdElem == N){
        printf("Fila cheia, impossivel inserir.\n");
        return;
    }
    if(f->qtdElem == 0){
        f->fila[0].chave = aux;
        f->inicio = f->fim = 0;
        f->qtdElem++;
        printf("Inserido no inicio da fila\n");
    }else{
        f->fim = (f->fim+1)%N;
        f->fila[f->fim].chave = aux;
        f->qtdElem++;
        printf("Inserido ao final da fila\n");
    }
}

void imprimeFila(FilaEstatica f){
    printf("Fila: { ");
    for(int i = 0; i < f.qtdElem; i++){
        printf("%d ", f.fila[(f.inicio+i)%N].chave);
    }
    printf("}\n");
}

int main(){
    FilaEstatica fila;
    iniciaFila(&fila);
    if(estaVazia(fila) == 1){
        printf("Fila vazia.\n");
    }

    inserirFila(&fila, 1);
    inserirFila(&fila, 2);
    inserirFila(&fila, 3);
    inserirFila(&fila, 4);
    inserirFila(&fila, 5);
    inserirFila(&fila, 6);
    inserirFila(&fila, 7);
    inserirFila(&fila, 8);
    inserirFila(&fila, 9);
    imprimeFila(fila);
    return 0;
}