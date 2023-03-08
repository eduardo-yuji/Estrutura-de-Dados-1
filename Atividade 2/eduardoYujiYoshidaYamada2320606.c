/**
 * @file eduardoYujiYoshidaYamada2320606.c
 * @author Eduardo Yuji Yoshida Yamada (eduardoyuji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

//Arquivo
typedef struct ObjetoVisita{
    char chaveE[50];
}ObjetoVisita;

typedef struct FilaE{
    ObjetoVisita fila[N];
    int inicioE;
    int fimE;
    int quantidadeE;
}FilaE;

//Visitas concretizadas
typedef struct NoFilaC* ptrNoFilaC;

typedef struct NoFilaC{
    int chaveC;
    ptrNoFilaC proximoC;
}   NoFilaC;

typedef struct FilaDinamicaC{
    ptrNoFilaC inicioC;
    ptrNoFilaC fimC;
    int tamanhoC;
} FilaC;

//Visitas não concretizadas
typedef struct NoFilaNC* ptrNoFilaNC;

typedef struct NoFilaNC{
    int chaveNC;
    ptrNoFilaC proximoNC;
}   NoFilaNC;

typedef struct FilaDinamicaNC{
    ptrNoFilaNC inicioNC;
    ptrNoFilaNC fimNC;
    int tamanhoNC;
} FilaNC;

void iniciaFilaE(FilaE *f){
    f->inicioE = 0;
    f->fimE = 9;
    f->quantidadeE = 0;
}

void iniciaFilaC(FilaC *f){
    f->inicioC = f->fimC = NULL;
    f->tamanhoC = 0;
}

void iniciaFilaNC(FilaNC *f){
    f->inicioNC = f->fimNC = NULL;
    f->tamanhoNC = 0;
}

bool estaVaziaE(FilaE *f){
    return(f->quantidadeE == 0);
}

bool estaVaziaC(FilaC *f){
    return (f->tamanhoC == 0);
}

bool estaVaziaNC(FilaNC *f){
    return (f->tamanhoNC == 0);
}

void insereFilaE(FilaE *f, char aux[50]){
    if(f->quantidadeE == 0){
        strcpy(f->fila[0].chaveE, aux);
        f->inicioE = f->fimE = 0;
        f->quantidadeE++;
        printf("Inserido no inicio da fila\n");
    }else{
        f->fimE = (f->fimE+1)%N;
        strcpy(f->fila[f->fimE].chaveE, aux);
        f->quantidadeE++;
        printf("Inserido ao final da fila\n");
    }
}

void imprimeFila(FilaE f){
    printf("Fila:\n");
    for(int i = 0; i < f.quantidadeE; i++){
        printf("%s", f.fila[(f.inicioE+i)%N].chaveE);
    }
    printf("\n");
}

int main(int argc, const char* argv[]){
    FILE *arq1;
    FilaE filaE;
    FilaC filaC;
    FilaNC filaNC;

    char recebe[50];
    
    //Abre os arquivos
    arq1 = fopen(argv[1],"r");

    //verifica a integridade dos arquivos
    if(arq1 == NULL){
        printf("Erro Na abertura do arquivo 1.\n");
    }
    
    iniciaFilaE(&filaE);
    iniciaFilaC(&filaC);
    iniciaFilaNC(&filaNC);

    for(int i = 0; i < 10; i++){
        fgets(recebe, 50, arq1);
        insereFilaE(&filaE, recebe);
    }

    imprimeFila(filaE);

    fclose(arq1);

    return 0;
}