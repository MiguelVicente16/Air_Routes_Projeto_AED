/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288)S e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 04/12/2020
*
* NOME
*   EncontrarMST.c
*
* DESCRIÇÃO
*   Conjunto de funções que permitem a determinação da MST
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
#include "EncontrarMST.h"


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

typedef struct subgrafo {
  int superior;
  int grandeza;
}subgrafo;



/******************************************************************************
 * KruskalMST()
 *
 * Arguments: Info - ponteiro para estrutura de dados do tipo AirRoutes
 *            mst - ponteiro para estrutura de dados do tipo MST
 * Retorna: ponteiro para estrutura do tipo MST
 *
 * Descrição: Realização do Algoritmo de Kruskal, que permite construir a MST,
 *          utilizando o qsort como algortimo de ordenação
 *
 *****************************************************************************/
MST * KruskalMST(AirRoutes * Info, MST * mst){
  mst->edge = (Edge*)calloc((GetInfo_V(Info)) , (sizeof(Edge)));
  int mst_aux = 0;
  int i = 0;

  qsort(Info->graph, GetInfo_E(Info), sizeof(Info->graph[0]), Compare_1);
  subgrafo * subgrafos = (subgrafo*)malloc((GetInfo_V(Info)+1) * sizeof(subgrafo));

  for (int v = 0; v < GetInfo_V(Info)+1; ++v) {
    subgrafos[v].superior = v;
    subgrafos[v].grandeza = 0;
  }

  while (mst_aux < GetInfo_V(Info)-1 && i < GetInfo_E(Info)) {
    //escolher a menor aresta
    Edge ProxEdge = Info->graph[i++];

    int x = FindMst(subgrafos, ProxEdge.V1);
    int y = FindMst(subgrafos, ProxEdge.V2);

    if (x != y) {
      mst->edge[mst_aux++] = ProxEdge;
      Union(subgrafos, x, y);
    }

  }
  qsort(mst->edge, GetInfo_V(Info), sizeof(mst->edge[0]), Compare_2);
  qsort(mst->edge, GetInfo_V(Info), sizeof(mst->edge[0]), Compare_3);
  mst->custo_total = 0;
  mst->total_edges = 0;
  mst->total_edges = mst_aux;
  mst->count = 0;
  for (i = 0; i < mst_aux + GetMst_count(mst); ++i)
  {
    if (GetMst_V1(mst,i) == 0 || GetMst_V2(mst,i) == 0) {
      mst->count++;
    }
    mst->custo_total += mst->edge[i].custo;
  }
  free(subgrafos);
  return mst;
}

/******************************************************************************
 * Compare_1()
 *
 * Argumentos: constante voids
 *
 * Retorna: 1 se o custo de a1 for maior
 *          0 se o custo de b1 for maior
 *
 *****************************************************************************/
int Compare_1(const void* a, const void* b){
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->custo > b1->custo;
}


/******************************************************************************
 * Compare_2()
 *
 * Argumentos: constante voids
 *
 * Retorna: 1 se o 1º vértice de a1 for maior que o de b1
 *          0 se o 1º vértice de b1 for maior que o de a1
 *
 *****************************************************************************/
int Compare_2(const void* a, const void* b){
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->V1 > b1->V1;
}


/******************************************************************************
 * Compare_3()
 *
 * Argumentos: constante voids
 *
 * Retorna: 0 caso 1º vértice de a1 e b1 sejam diferentes
 *          1 caso 1º vértice de a1 e b1 sejam iguais e o 2º vértice de a1
 *         for maior que o de b1
 *          0 caso 1º vértice de a1 e b1 sejam iguais e o 2º vértice de b1
 *         for maior que o de a1
 *****************************************************************************/
int Compare_3(const void* a, const void* b){
      struct Edge* a1 = (struct Edge*)a;
      struct Edge* b1 = (struct Edge*)b;
      if (a1->V1 == b1->V1) {
        return a1->V2 > b1->V2;
      }
      return 0;
}


/******************************************************************************
 * FindMst()
 *
 * Arguments: subgrafos - ponteiro para estrutura de dados do tipo subgrafo
 *            i - inteiro que representa o vértice superior
 * Retorna: vértice
 *
 * Descrição: Permite a compressão do caminho, tornando o algoritmo mais eficiente
 *
 *****************************************************************************/
int FindMst(subgrafo * subgrafos, int i){
    if (subgrafos[i].superior != i)
        subgrafos[i].superior = FindMst(subgrafos, subgrafos[i].superior);

    return subgrafos[i].superior;
}


/******************************************************************************
 * Union()
 *
 * Arguments: Info - ponteiro para estrutura de dados do tipo AirRoutes
 *            mst - ponteiro para estrutura de dados do tipo MST
 * Retorna: void
 *
 * Descrição: Obtenção do backbone do grafo original
 *
 *****************************************************************************/
void Union(subgrafo * subgrafos, int x, int y){
  int raizx = FindMst(subgrafos, x);
  int raizy = FindMst(subgrafos, y);

  if (subgrafos[raizx].grandeza < subgrafos[raizy].grandeza)
  subgrafos[raizx].superior = raizy;
  else if (subgrafos[raizx].grandeza > subgrafos[raizy].grandeza)
  subgrafos[raizy].superior = raizx;
  else
  {
    subgrafos[raizy].superior = raizx;
    subgrafos[raizx].grandeza++;
  }
}
