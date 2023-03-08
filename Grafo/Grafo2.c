#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct grafoM {
    int **matriz;
    int vertices;  //qtde de vértices
    int arestas;   //qtde arestas
    bool dirigido; //TRUE se for direcionado e FALSE se não direcionado
} GrafoMatriz;

void inicializa(GrafoMatriz *g, int vertices, bool dirigido){
    g->arestas = 0;
    g->vertices = vertices;
    g->dirigido = dirigido;

    g->matriz = (int**) malloc(vertices*sizeof(int*));
    for(int i=0; i<vertices; i++){
        g->matriz[i] = (int*) malloc(vertices*sizeof(int));

        for(int j=0; j<vertices; j++) {
            g->matriz[i][j] = 0;
        }
    }        
}

void destruir(GrafoMatriz *g){
    for(int i=0; i < g->vertices; i++){
        free(g->matriz[i]);
    }
    free(g->matriz);
}

void insereAresta(GrafoMatriz *g, int vsaida, int vchegada){
    g->arestas++;
    g->matriz[vsaida-1][vchegada-1]=1;

    if(g->dirigido==false){
        g->matriz[vchegada-1][vsaida-1]=1;
    }
}

void imprimeArestas(GrafoMatriz *g){
    for(int i=0; i < g->vertices; i++){
        for(int j=0; j < g->vertices; j++){
            if(g->matriz[i][j]>0){
                if(g->dirigido==true) printf("\n <%d,%d>", i+1, j+1);
                else printf("\n( %d, %d )", i+1, j+1);
            }
        }
    }
}

bool existeAresta(GrafoMatriz *g, int v1, int v2){
    return(g->matriz[v1-1][v2-1]>0);
}


int main(void){
    GrafoMatriz grafo;

    inicializa(&grafo, 5, true);

    insereAresta(&grafo, 1, 2);
    insereAresta(&grafo, 1, 3);
    insereAresta(&grafo, 2, 3);
    insereAresta(&grafo, 2, 5);
    insereAresta(&grafo, 3, 4);
    insereAresta(&grafo, 4, 5);

    imprimeArestas(&grafo);
    if(existeAresta(&grafo, 3, 4)==true) printf("\nA aresta existe");
    else printf("\nA aresta nao existe");

    destruir(&grafo);
    return EXIT_SUCCESS;
}