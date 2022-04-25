/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288)S e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 08/12/2020
*
* NOME
*   GetInfo.c
*
* DESCRIÇÃO
*   Funções abstratas de obtenção de valores das diferentes estruturas
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


/******************************************************************************
* GetInfo_V()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: v - inteiro da estrutura AirRoutes
*
*****************************************************************************/
int GetInfo_V(AirRoutes *Info){
  return Info->v;
}


/******************************************************************************
* GetInfo_E()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: e - inteiro da estrutura AirRoutes
*
*****************************************************************************/
int GetInfo_E(AirRoutes *Info){
  return Info->e;
}


/******************************************************************************
* GetInfo_Vertice()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: vertice - inteiro da estrutura AirRoutes
*
*****************************************************************************/
int GetInfo_Vertice(AirRoutes *Info){
  return Info->vertice;
}


/******************************************************************************
* GetInfo_Vertice_1()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: vertice_1 - inteiro da estrutura AirRoutes
*
*****************************************************************************/
int GetInfo_Vertice_1(AirRoutes *Info){
  return Info->vertice_1;
}


/******************************************************************************
* GetInfo_Vertice_2()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: vertice_2 - inteiro da estrutura AirRoutes
*
*****************************************************************************/
int GetInfo_Vertice_2(AirRoutes *Info){
  return Info->vertice_2;
}


/******************************************************************************
* GetMstEdge_Custo()
*
* Argumentos: mst - +onteiro para estrutura de dados do tipo MST
* Retorna: custo - double da estrutura AirRoutes
*
*****************************************************************************/
double GetMstEdge_Custo(MST * mst, int i){
  return mst->edge[i].custo;
}


/******************************************************************************
* GetMst_V1()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
* Retorna: V1 - inteiro da estrutura mst, tabela edge
*
*****************************************************************************/
int GetMst_V1(MST *mst, int i){
  return mst->edge[i].V1;
}


/******************************************************************************
* GetMst_V2()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
* Retorna: V2 - inteiro da estrutura mst, tabela edge
*
*****************************************************************************/
int GetMst_V2(MST *mst, int i){
  return mst->edge[i].V2;
}


/******************************************************************************
* GetInfo_GraphV1()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: V1 - inteiro da estrutura AirRoutes, tabela graph
*
*****************************************************************************/
int GetInfo_GraphV1(AirRoutes *Info, int i){
  return Info->graph[i].V1;
}


/******************************************************************************
* GetInfo_GraphV2()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: V2 - inteiro da estrutura AirRoutes, tabela graph
*
*****************************************************************************/
int GetInfo_GraphV2(AirRoutes *Info, int i){
  return Info->graph[i].V2;
}


/******************************************************************************
* GetMst_TotalEdges()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
* Retorna: total_edges - inteiro da estrutura mst
*
*****************************************************************************/
int GetMst_TotalEdges(MST * mst){
  return mst->total_edges;
}


/******************************************************************************
* GetMst_count()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
* Retorna: count - inteiro da estrutura mst
*
*****************************************************************************/
int GetMst_count(MST * mst){
  return mst->count;
}


/******************************************************************************
* GetMst_CustoTotal()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
* Retorna: custo_total - double da estrutura mst
*
*****************************************************************************/
double GetMst_CustoTotal(MST * mst){
  return mst->custo_total;
}
