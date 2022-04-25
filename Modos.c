/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288) e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 09/12/2020
*
* NOME
*   Modos.c
*
* DESCRIÇÃO
*   Conjunto de funções que referentes às diferentes variantes do problema
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
#include "ManipularMST.h"
#include "Graph.h"
#include "Matriz.h"

typedef struct AirRoutes {
  int v, e, vertice_1, vertice_2, vertice, count;
  struct Edge* graph;
}AirRoutes;

typedef struct Edge {
  int V1, V2;
  double custo;
} Edge;

typedef struct MST{
  int total_edges,count;
  double custo_total;
  struct Edge* edge;
}MST;

/******************************************************************************
 * ModoA1()
 *
 * Argumentos: fp - pointeiro para ficheiro de entrada
*             fout - ponteiro para ficheiro de saída
 *            Info - ponteiro para estrutura de dados do tipo AirRoutes
 * Retorna: void
 *
 * Descrição: Obtenção do backbone do grafo original
 *
 *****************************************************************************/
 void ModoA1(FILE *fp, FILE *fout, AirRoutes * Info){
   MST graph;
   AllocGraph(Info);
   FillGraph(fp, Info);
   MST * mst = KruskalMST(Info, &graph);
   fprintf(fout, " %d %.2lf\n", GetMst_TotalEdges(mst), GetMst_CustoTotal(mst) );
   PrintMst(Info, mst, fout);
   fprintf(fout, "\n");
   free(Info->graph);
   free(mst->edge);
 }


 /******************************************************************************
  * ModoB1()
  *
  * Arguments: fp - pointeiro para ficheiro de entrada
  *             fout - ponteiro para ficheiro de saída
  *            Info - ponteiro para estrutura de dados do tipo AirRoutes
  * Retorna: void
  *
  * Descrição: Obtém o "backbone" variacional em relação à solução obtida
  *          em A1 por exclusão da aresta entre dois vértice
  *
  *****************************************************************************/

  void ModoB1(FILE *fp, FILE *fout, AirRoutes * Info) {
    MST graph;
    int find = 0;
    AllocGraph(Info);
    FillGraph(fp, Info);
    MST * mst = KruskalMST(Info, &graph);
    fprintf(fout, " %d %.2lf", GetMst_TotalEdges(mst), GetMst_CustoTotal(mst));
    find = FindEdgeGraph(mst,Info);
    if (find == -1) {
      fprintf(fout, " -1\n");
      PrintMst(Info, mst, fout);
      fprintf(fout,"\n");
      free(Info->graph);
      free(mst->edge);
      return;
    }
    find = FindEdgemst(mst, Info);
    if (find == 0) {
      fprintf(fout, " 0\n");
      PrintMst(Info, mst, fout);
      fprintf(fout,"\n");
      free(Info->graph);
      free(mst->edge);
      return;
    }
    MST graph2;
    MST * mst2 = KruskalMST(Info, &graph2);
    free(Info->graph);
    CompararMst(Info, mst, mst2, fout,1);
    free(mst->edge);
    free(mst2->edge);
    fprintf(fout,"\n");
    return;
  }


   /******************************************************************************
   * ModoC1()
   *
   * Arguments: fp - pointeiro para ficheiro de entrada
   *            fout - ponteiro para ficheiro de saída
   *            Info - ponteiro para estrutura de dados do tipo AirRoutes
   * Retorna: void
   *
   * Descrição: Obtém o "backbone" não variacional  por exclusão da aresta entre
   *            dois vértice
   *
   *****************************************************************************/
   void ModoC1(FILE *fp, FILE *fout, AirRoutes * Info) {
     MST graph;
     int find = 0;
     AllocGraph(Info);
     FillGraph(fp, Info);
     MST * mst = KruskalMST(Info, &graph);
     fprintf(fout, " %d %.2lf", GetMst_TotalEdges(mst), GetMst_CustoTotal(mst));
     find = FindEdgemst(mst, Info);
     if (find == 0) {
       fprintf(fout, " -1\n");
       PrintMst(Info, mst, fout);
       fprintf(fout,"\n");
       free(Info->graph);
       free(mst->edge);
       return;
     }
     find = FindEdgeGraph(mst,Info);
     if (find == -1) {
       fprintf(fout, " -1\n");
       PrintMst(Info, mst, fout);
       fprintf(fout,"\n");
       free(Info->graph);
       free(mst->edge);
       return;
     }
     MST graph2;
     MST * mst2 = KruskalMST(Info, &graph2);
     free(Info->graph);
     CompararMst(Info, mst, mst2, fout,2);
     free(mst->edge);
     free(mst2->edge);
     fprintf(fout,"\n");
     return;
   }


  /******************************************************************************
  * ModoD1()
  *
  * Arguments: fp - pointeiro para ficheiro de entrada
 *             fout - ponteiro para ficheiro de saída
  *            Info - ponteiro para estrutura de dados do tipo AirRoutes
  * Retorna: void
  *
  * Descrição: Obtém o "backbone" variacional por exclusão de um vértice
  *****************************************************************************/
  void ModoD1(FILE *fp, FILE *fout, AirRoutes * Info) {
    MST graph;
    int find = 0;
    AllocGraph(Info);
    FillGraph(fp, Info);
    MST * mst = KruskalMST(Info, &graph);
    fprintf(fout, " %d %.2lf", GetMst_TotalEdges(mst), GetMst_CustoTotal(mst));
    find = RemoveVertice(mst,Info);
    if (find == 0) {
      fprintf(fout, " -1\n");
      PrintMst(Info, mst, fout);
      fprintf(fout,"\n");
      free(Info->graph);
      free(mst->edge);
      return;
    }
    MST graph2;
    MST * mst2 = KruskalMST(Info, &graph2);
    free(Info->graph);
    CompararMst(Info, mst, mst2, fout, 3);
    free(mst->edge);
    free(mst2->edge);
    fprintf(fout,"\n");
    return;
  }


  /******************************************************************************
   * ModoE1()
   *
   * Arguments: fp - pointeiro para ficheiro de entrada
  *             fout - ponteiro para ficheiro de saída
   *            Info - ponteiro para estrutura de dados do tipo AirRoutes
   * Retorna: void
   *
   * Descrição: Obtém o "backbone" e o respetivo "backup"
   *****************************************************************************/
   void ModoE1(FILE *fp, FILE *fout, AirRoutes * Info) {
     MST graph;
     Edge save;
     int i = 0;
     AllocGraph(Info);
     FillGraph(fp, Info);
     MST * mst = KruskalMST(Info, &graph);
     fprintf(fout, "%d %.2lf\n", GetMst_TotalEdges(mst), GetMst_CustoTotal(mst));
     Matriz *matriz = AlocarMatriz(Info);
     PreencherMatriz(matriz,mst);
     while (i < GetMst_TotalEdges(mst) + GetMst_count(mst)) {
       if (GetMst_V1(mst,i) > 0 && GetMst_V2(mst,i) > 0) {
         Info->vertice_1 = GetMst_V1(mst,i);
         Info->vertice_2 = GetMst_V2(mst,i);
         save = FindEdgeGraph2(mst,Info);
         fprintf(fout,"%d %d %.2lf", GetMst_V1(mst,i), GetMst_V2(mst,i), GetMstEdge_Custo(mst, i));
         MST graph2;
         MST * mst2 = KruskalMST(Info, &graph2);
         CompararMst2(Info,mst, mst2, fout, matriz);
         free(mst2->edge);
         Info->graph[0] = save;
       }
       i++;
     }
     fprintf(fout,"\n");
     free(Info->graph);
     free(mst->edge);
     FreeMatriz(Info, matriz);
     return;
   }
