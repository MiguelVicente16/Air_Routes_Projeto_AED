/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288)S e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 09/12/2020
*
* NOME
*   Matriz.c
*
* DESCRIÇÃO
*   Conjunto de funções de manipulação da matriz de adjacência
*
* COMENTÁRIOS
*
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

#include "Abstratos.h"

typedef struct MST{
  int total_edges,count;
  double custo_total;
  struct Edge* edge;
}MST;

typedef struct Edge {
  int V1, V2;
  double custo;
} Edge;

typedef struct AirRoutes {
  int v, e, vertice_1, vertice_2, vertice, count;
  struct Edge* graph;
}AirRoutes;

typedef struct Matriz{
  char **adj;
} Matriz;

/******************************************************************************
 * AlocarMatriz()
 *
 * Arguments: Info - ponteiro para estrutura de dados do tipo AirRoutes
 *
 * Retorna: ponteiro para estrutura do tipo Matriz
 *
 * Descrição: aloca toda a estrutura Matriz
 *
 *****************************************************************************/
Matriz *AlocarMatriz(AirRoutes *Info){

  Matriz *matriz = (Matriz *)calloc(1,sizeof(Matriz));
  if (matriz == NULL){
    exit (0);
  }
  matriz->adj = (char **)calloc(GetInfo_V(Info)+1 , sizeof(char *));
  if (matriz->adj == NULL){
    exit(0);
  }
  for (int i = 1; i <= GetInfo_V(Info); i++){
    matriz->adj[i] = (char *)calloc(GetInfo_V(Info)+1 , sizeof(char));
    if (matriz->adj[i] == NULL)
    {
      exit(0);
    }
  }
  return matriz;
}


/******************************************************************************
 * PreencherMatriz()
 *
 * Arguments: matriz - ponteiro para estrutura de dados do tipo Matriz
 *            mst - ponteiro para estrutura de dados do tipo mst
 * Retorna: void
 *
 * Descrição: Preenche a matriz de adjecência com um valor 1 caso exista uma
 *           aresta composta pelos vértices V1 e V2
 *
 *****************************************************************************/
void PreencherMatriz(Matriz *matriz, MST * mst){
  for (int i = 0; i < GetMst_TotalEdges(mst)+GetMst_count(mst); i++) {
    if (GetMst_V1(mst,i) != 0 && GetMst_V2(mst,i) != 0) {
    matriz->adj[GetMst_V1(mst,i)][GetMst_V2(mst,i)] = '1';
    }
  }
}


/******************************************************************************
 * FreeMatriz()
 *
 * Arguments: Info - ponteiro para estrutura de dados do tipo AirRoutes
 *            matriz - ponteiro para estrutura de dados do tipo Matriz
 * Retorna: void
 *
 * Descrição: Liberta a memória alocada pela estrutura do tipo Matriz
 *
 *****************************************************************************/
void FreeMatriz(AirRoutes *Info, Matriz *matriz){

  for (int i = 1; i <= GetInfo_V(Info); i++)
    free(matriz->adj[i]);

  free(matriz->adj);
  free(matriz);

  return;
}
