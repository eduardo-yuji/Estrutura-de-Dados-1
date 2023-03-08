#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noArv* ptrNoArv;

typedef struct noArv{
    int chave;
    ptrNoArv direita;
    ptrNoArv esquerda;
}NoArv;

void iniciaRaiz(NoArv **no){
    *no = NULL;
}

void insereArvore(NoArv **no, int x){
    if((*no)==NULL){
        *no = (NoArv*)malloc(sizeof(NoArv));
        (*no)->chave = x;
        (*no)->esquerda = (*no)->direita = NULL;
        return;
    }
    if((*no)->chave == x){
        printf("Elemento ja inserido.\n");
        return;
    }
    if((*no)->chave > x){
        insereArvore(&(*no)->esquerda, x);
    }else{
        insereArvore(&(*no)->direita, x);
    }
}

void imprimeEmOrdem(NoArv **no){
    if((*no)==NULL){
        return;
    }
    imprimeEmOrdem(&(*no)->esquerda);
    printf("%d\n", (*no)->chave);
    imprimeEmOrdem(&(*no)->direita);
}

void imprimePosOrdem(NoArv **no){
    if((*no)==NULL){
        return;
    }
    imprimePosOrdem(&(*no)->direita);
    printf("%d\n", (*no)->chave);
    imprimePosOrdem(&(*no)->esquerda);
}

void imprimePreOrdem(NoArv **no){
    if((*no)==NULL){
        return;
    }
    printf("%d\n",(*no)->chave);
    imprimePreOrdem(&(*no)->esquerda);
    imprimePreOrdem(&(*no)->direita);
}

void cortaArvore(NoArv **no){
    if(*no == NULL){
        return;
    }
    cortaArvore(&(*no)->esquerda);
    cortaArvore(&(*no)->direita);
    free(*no);
    (*no) == NULL;
}

NoArv* buscaFolha(NoArv **no, int x){
    if((*no) == NULL){
        return(*no);
    }
    if((*no)->chave == x){
        return (*no);
    }
    if((*no)->chave > x){
        return(buscaFolha(&(*no)->esquerda,x));
    }else{
        return(buscaFolha(&(*no)->direita,x));
    }
}

NoArv* maiorElemento(NoArv **no){
    if((*no)->direita == NULL){
        NoArv* aux = (*no);
        if((*no)->esquerda != NULL){
            *no = (*no)->esquerda;
            return aux;
        }else{
            *no = NULL;
            return aux;
        }
    }
    return maiorElemento(&(*no)->direita);
}

bool excluirFolha(NoArv **no, int x){
    if((*no) == NULL) return false;
    if((*no)->chave == x){
        if((*no)->esquerda == NULL && (*no)->direita == NULL){
            free(*no);
            (*no) = NULL;
            return true;
        }
        if((*no)->direita == NULL){
            NoArv* aux = (*no);
            (*no) = (*no)->esquerda;
            free(aux);
            return true;
        }
        if((*no)->esquerda == NULL){
            NoArv* aux = (*no);
            (*no) = (*no)->direita;
            free(aux);
            return true;
        }
        NoArv* elem = maiorElemento(&(*no)->esquerda);
        elem->esquerda = (*no)->esquerda;
        elem->direita = (*no)->direita;
        NoArv* aux = (*no);
        (*no) = elem;
        free(aux);
        return true;
    }
    if((*no)->chave > x) excluirFolha(&(*no)->esquerda, x);
    else excluirFolha(&(*no)->direita , x);
}

int main(){
    NoArv *raiz;
    iniciaRaiz(&raiz);
    insereArvore(&raiz, 15);
    insereArvore(&raiz, 02);
    insereArvore(&raiz, 28);
    insereArvore(&raiz, 93);
    insereArvore(&raiz, 10);
    insereArvore(&raiz, 20);
    insereArvore(&raiz, 8);
    insereArvore(&raiz, 4);
    insereArvore(&raiz, 1);
    insereArvore(&raiz, 0);
    

    printf("  Em Ordem:\n");
    imprimeEmOrdem(&raiz);
    printf("  Pos Ordem:\n");
    imprimePosOrdem(&raiz);
    printf("  Pre Ordem:\n");
    imprimePreOrdem(&raiz);
    
    int x;
    printf("Digite o elemento: ");
    scanf("%d",&x);
    fflush(stdin);
    if(buscaFolha(&raiz, x)==NULL){
        printf("Elemento n encontrado");
    }else{
        printf("Elemento %d na arvore\n", x);
    }

    excluirFolha(&raiz, 2);
    printf("  Pre Ordem:\n");
    imprimePreOrdem(&raiz);

    cortaArvore(&raiz);
    return 0;
}