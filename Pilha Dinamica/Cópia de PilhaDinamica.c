#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
    struct nopilha* prox; /*struct no pilha pois para o compilador ainda não existe a estrutura nopilha*/
}NoPilha;

typedef struct{
    NoPilha* topo;
    int n;

}PilhaDinamica;

void iniciaPilha(PilhaDinamica *p){
    p->topo = NULL;
    p->n = 0;
}

int tamanhoPilha(PilhaDinamica p){
    return p.n;
}

bool estaVazia(PilhaDinamica p){
    if(p.n == 0){
        printf("Pilha Vazia\n");
        return true;
    }else{
        printf("Pilha nao vazia\n");
        return false;
    }
}

void inserir(PilhaDinamica *p, int x){
    NoPilha *aux;
    aux = malloc(sizeof(NoPilha));
    aux->chave = x;
    aux->prox = p->topo;
    p->topo = aux;
    p->n++;
    printf("\n-----Inserido com sucesso!-----\n");
}

void remover(PilhaDinamica *p){
    NoPilha *aux;
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    p->n--;
    printf("\n-----Removido com sucesso!-----\n");
}

int verificaTopo(PilhaDinamica *p){
    if(!estaVazia(p)){
        return p->topo->chave;
    }else{
        printf("pilha vazia\n");
    }
}
int main(void){
    PilhaDinamica pilha;
    iniciaPilha(&pilha);
    estaVazia(pilha);
    printf("Tamanho da pilha: %d\n",tamanhoPilha(pilha));

    inserir(&pilha,5);
    printf("\nTamanho da pilha: %d\n",tamanhoPilha(pilha));
    //printf("topo->%d\n",pilha.topo->chave);
    //remover(&pilha);
    printf("\nTopo da pilha: %d\n",verificaTopo(&pilha));

    inserir(&pilha,6);
    printf("\nTamanho da pilha: %d\n",tamanhoPilha(pilha));
    printf("\nTopo da pilha: %d\n",verificaTopo(&pilha));

    remover(&pilha);   remover(&pilha);
    estaVazia(pilha);
    printf("\nTopo da pilha: %d\n",verificaTopo(&pilha));

    return 0;
}