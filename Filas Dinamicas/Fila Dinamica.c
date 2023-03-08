/**
 * @file Fila Dinamica.c
 * @author Eduardo Yuji Yoshida Yamada (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoFila* ptrNoFila;

typedef struct NoFila{
    int chave;
    ptrNoFila proximo;
}   NoFila;

typedef struct FilaDinamica{
    ptrNoFila inicio;
    ptrNoFila fim;
    int tamanho;
} FilaD;

void iniciaFila(FilaD *f){
    f->inicio = f->fim = NULL;
    f->tamanho = 0;
}

bool estaVazia(FilaD *f){
    return (f->tamanho == 0);
}

int tamanhoFila(FilaD *f){
    return (f->tamanho);
}

void insereFila(FilaD *f, int x){
    ptrNoFila aux = (NoFila*)malloc(sizeof(NoFila));
    aux->chave = x;
    if(estaVazia(f) == 1){
        f->inicio = f->fim = aux;
        f->fim->proximo = NULL;
        f->tamanho ++;
    }else{
        f->fim->proximo = aux;
        f->fim = aux;
        aux->proximo = NULL;
        f->tamanho ++;
    }
}

void imprimeFila(FilaD *f){
    ptrNoFila percorre;
    if(!estaVazia(f)){
        printf("Fila = { ");
        for (percorre = f->inicio; percorre != NULL; percorre = percorre->proximo){
            printf("%d ",percorre->chave);
        }
        printf("}\n");
    }else{
        printf("Pilha Vazia.\n");
    }
}

int desenFila(FilaD *f){
    if(!estaVazia(f)){
        ptrNoFila aux = f->inicio;
        int x = aux->chave;
        f->inicio = f->inicio->proximo;
        free(aux);
        f->tamanho --;
        return x;
    }else{
        printf("Fila Vazia! Impossivel remover.\n");
        return -999;
    }
}

int main(void){
    FilaD fila;
    int x, tamanho;
    iniciaFila(&fila);
    insereFila(&fila, 10);
    insereFila(&fila, 30);
    insereFila(&fila, 50);
    insereFila(&fila, 40);
    insereFila(&fila, 20);
    imprimeFila(&fila);

    tamanho = fila.tamanho;
    
    printf("Removendo da fila: { ");
    for(int i = 0; i < tamanho; i++){
        x = desenFila(&fila);
        printf("%d ",x);
    }
    printf("}\n");

    imprimeFila(&fila);

    return 0;
}