#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct grafoM{
    int **matriz;
    int vertices;
    int arestas;
    bool dirigido;
} GrafoMatriz;

void inicializaGrafo(GrafoMatriz *g, int vertices, bool dirigido){
    g->arestas = 0;
    g->vertices = vertices;
    g->dirigido = dirigido;
    g->matriz = (int**) malloc(vertices*sizeof(int*));
    for(int i = 0; i < vertices; i++){
        g->matriz[i] = (int*) malloc(vertices*sizeof(int));
        for(int j = 0; j < vertices; j++){
            g->matriz[i][j] = 0;
        }
    }
}

void insereAresta(GrafoMatriz *g, int vsaida, int vchegada){
    g->arestas++;
    g->matriz[vsaida][vchegada] = 1;

    if(g->dirigido == false){
        g->matriz[vchegada][vsaida] = 1;
    }
}

void destroiGrafo(GrafoMatriz *g){
    for(int i = 0; i < g->vertices; i++){
            free(g->matriz[i]);
    }
    free(g->matriz);
}

void imprimeArestas(GrafoMatriz *g){
    for(int i = 0; i < g->vertices; i++){
        for(int j = 0; j < g->vertices; j++){
            if(g->matriz[i][j] > 0){
                if(g->dirigido == true) 
                    printf("<%d,%d> = %d\n", i, j, g->matriz[i][j]);
                else{
                    printf("<%d,%d> = %d\n", i, j, g->matriz[i][j]);
                    printf("<%d,%d> = %d\n", j, i, g->matriz[j][i]);
                }
            }
        }
    }
}

bool existeAresta(GrafoMatriz *g, int v1, int v2){
    return(g->matriz[v1][v2]>0);
}

int main(void){
    GrafoMatriz grafo;
    inicializaGrafo(&grafo, 6, true);

    insereAresta(&grafo, 1, 2);
    insereAresta(&grafo, 1, 3);
    insereAresta(&grafo, 2, 3);
    insereAresta(&grafo, 2, 5);
    insereAresta(&grafo, 3, 4);
    insereAresta(&grafo, 4, 5);

    imprimeArestas(&grafo);
    if(existeAresta(&grafo, 3, 5) == true)
        printf("Aresta existe\n");
    else
        printf("Aresta nao existe\n");
    destroiGrafo(&grafo);
    return 0;
}