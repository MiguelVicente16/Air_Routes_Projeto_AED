/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288)S e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 08/12/2020
*
* NOME
*   Graph.c
*
* DESCRIÇÃO
*   Conjunto das funções que afetam a estrutura graph do tipo edge
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

typedef struct Edge {
  int V1, V2;
  double custo;
} Edge;

typedef struct AirRoutes {
  int v, e, vertice_1, vertice_2, vertice, count;
  struct Edge* graph;
}AirRoutes;


/******************************************************************************
 * AllocGraph()
 *
 * Arguments: Info - ponteiro para estrutura de dados do tipo AirRoutes
 *
 * Retorna: void
 *
 * Descrição: Aloca a memória necessária
 *
 *****************************************************************************/
void AllocGraph(AirRoutes * Info){
  Info->graph = (Edge*)malloc((GetInfo_E(Info)) * (sizeof(struct Edge)));
  return;
}


/***********************************************************************************
 * FillGraph()
 *
 * Arguments: fp - pointeiro para ficheiro de entrada
 *            Info - ponteiro para estrutura de dados do tipo AirRoutes
 *
 * Retorna: void
 *
 * Descrição: Preenche um vetor de arestas (Info->graph) com os dados referentes ao grafo
 *
 ***********************************************************************************/
void FillGraph(FILE * fp, AirRoutes * Info){
  int i = 0, aux = 0;
  while (i < GetInfo_E(Info)) {
    if(fscanf(fp,"%d %d %lf", &Info->graph[i].V1, &Info->graph[i].V2, &Info->graph[i].custo));
    if (GetInfo_GraphV1(Info, i) > GetInfo_GraphV2(Info, i)) {
      aux = GetInfo_GraphV1(Info, i);
      Info->graph[i].V1 = GetInfo_GraphV2(Info, i);
      Info->graph[i].V2 = aux;
    }
    i++;
  }
}
