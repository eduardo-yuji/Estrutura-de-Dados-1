#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noLista *ptrNoLista;

typedef struct noLista{
    int chave;
    ptrNoLista prox;
} NoLista;

typedef struct listaEncadeada{
    NoLista* inicio;
    int tam;
}Lista;

void iniciaLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

bool estaVazia(Lista *l){
    return(l->tam == 0);
}

int quantidadeElementos(Lista *l){
    return(l->tam);
}

int insereElemento(Lista *l, int x){
    ptrNoLista novoE = malloc(sizeof(NoLista)); // ptrNoLista novoE = (NoLista*) malloc(sizeof(NoLista))
    novoE->chave = x;
    novoE->prox = NULL;
    if(estaVazia(l) == 1){
        l->inicio = novoE;
    }else{
        if(l->inicio->chave > x){
            novoE->prox = l->inicio;
            l->inicio = novoE;
        }else{
            ptrNoLista aux = l->inicio;
            while(aux->prox != NULL && aux->prox->chave < x){
                aux = aux->prox;
            }
            novoE->prox = aux->prox;
            aux->prox = novoE;
        }
    }
    l->tam++;
}

void imprimeLista(Lista *l){
    ptrNoLista aux = l->inicio;
    printf("Lista Ordenada:\n[ ");
    while(aux != NULL){
        printf("%d ",aux->chave);
        aux = aux->prox;
    }
    printf("]\n");
}

void pesquisaNaLista(Lista *l){
    ptrNoLista aux = l->inicio;
    int busca, i = 1, confere = -999;
    printf("Digite o numero para pesquisa: ");
    scanf("%d", &busca);
    fflush(stdin);
    while(aux != NULL){
        if(aux->chave == busca){
            printf("Elemento encontrado. Posicao: %d  Elemento: %d\n", i, aux->chave);
            confere = 0;
        }
        i++;
        aux = aux->prox;
    }
    if(confere != 0){
        printf("Elemento nao encontrado.\n");
    }
}

void destroiLista(Lista *l){
    ptrNoLista aux = l->inicio;
    while(l->inicio != NULL){
        l->inicio = l->inicio->prox;
        free(aux);
        aux = l->inicio;
    }
    printf("Lista destruida.\n");
}

int main(void){
    Lista lista;

    iniciaLista(&lista);

    insereElemento(&lista, 0);
    insereElemento(&lista, 5);
    insereElemento(&lista, 3);
    insereElemento(&lista, -2);
    insereElemento(&lista, 20);
    insereElemento(&lista, 10);

    imprimeLista(&lista);

    pesquisaNaLista(&lista);

    destroiLista(&lista);

    return EXIT_SUCCESS;
}