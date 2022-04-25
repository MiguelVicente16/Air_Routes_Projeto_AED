/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288)S e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 04/12/2020
*
* NOME
*   ManiularMST.c
*
* DESCRIÇÃO
*   Conjunto das funções que permitem manipular e trabalhar com uma MST
*   previamente determinada
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
#include "ManipularMST.h"

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
 * PrintMst()
 *
 * Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
 *            mst - ponteiro para estrutura de dados do tipo MST
 *            fout - ponteiro para ficheiro de saída
 * Retorna: void
 *
 * Descrição: Imprime dois vértices que formam uma aresta e o custo desta
 *
 *****************************************************************************/
  void PrintMst(AirRoutes * Info, MST * mst, FILE * fout){
    int i = 0;
    for (i = 1; i < GetMst_TotalEdges(mst) + GetMst_count(mst); ++i)
    {
      if (GetMst_V1(mst,i) != 0 && GetMst_V2(mst,i)!= 0) {
        fprintf(fout,"%d %d %.2lf\n", GetMst_V1(mst,i), GetMst_V2(mst,i), GetMstEdge_Custo(mst,i));
      }
    }
  }


/******************************************************************************
 * FindEdgemst()
 *
 * Argumentos: mst - ponteiro para estrutura de dados do tipo MST
 *            Info - ponteiro para estrutura de dados do tipo AirRoutes
 * Retorna: 1 se a encontrar a aresta
 *          0 se não a encontrar
 *
 * Descrição: Verifica se a aresta pertence à MST
 *
 *****************************************************************************/
 int FindEdgemst(MST * mst, AirRoutes * Info){
   int find = 0;
   for (int i = 1; i < GetMst_TotalEdges(mst)+GetMst_count(mst); i++) {
     if ((GetMst_V1(mst,i) == GetInfo_Vertice_1(Info) && GetMst_V2(mst,i) == GetInfo_Vertice_2(Info))
     || (GetMst_V1(mst,i) == GetInfo_Vertice_2(Info) && GetMst_V2(mst,i) == GetInfo_Vertice_1(Info))){
       find++;
       break;
     }
   }
   return find;
 }


 /****************************************************************************************
  * FindEdgeGraph()
  *
  * Argumentos: mst - ponteiro para estrutura de dados do tipo MST
  *            Info - ponteiro para estrutura de dados do tipo AirRoutes
  * Retorna: 0se encontrar a aresta
  *          -1 se não a encontrar
  *
  * Descrição: Verifica se a aresta pertence ao grafo, retirando-a, para os modos B1 e C1
  *
  ***************************************************************************************/
 int FindEdgeGraph(MST * mst, AirRoutes * Info){
   int find = -1, i = 0;
   if ((GetInfo_Vertice_1(Info) <= 0) || (GetInfo_Vertice_2(Info) <= 0)) {
     find = -1;
     return find;
   }
   for (i = 0; i < GetInfo_E(Info); i++) {
     if ((GetInfo_GraphV1(Info, i) == GetInfo_Vertice_1(Info) && GetInfo_GraphV2(Info, i) == GetInfo_Vertice_2(Info))
     || (GetInfo_GraphV1(Info, i) == GetInfo_Vertice_2(Info)  && GetInfo_GraphV2(Info, i) == GetInfo_Vertice_1(Info))){
       Info->graph[i].V1 = 0;
       Info->graph[i].V2 = 0;
       Info->graph[i].custo = 0;
       find++;
       break;
     }
   }
   return find;
 }


/******************************************************************************
* FindEdgeGraph2()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
*            Info - ponteiro para estrutura de dados do tipo AirRoutes
*
* Retorna: save - estrutura de tipo edge que salvaguarda a aresta retirada
*
* Descrição: Verifica se a aresta pertence ao grafo, retirando-a, para o modo E1.
*            No entanto, salvaguarda a aresta que se retirou para futura utilização
*
*****************************************************************************/
Edge FindEdgeGraph2(MST * mst, AirRoutes * Info){
  int i = 0;
  Edge save;
  for (i = 0; i < GetInfo_E(Info); i++) {
    if ((GetInfo_GraphV1(Info,  i) == GetInfo_Vertice_1(Info) && GetInfo_GraphV2(Info, i) == GetInfo_Vertice_2(Info))
    || (GetInfo_GraphV1(Info,  i) == GetInfo_Vertice_2(Info) && GetInfo_GraphV2(Info, i) == GetInfo_Vertice_1(Info))) {
      save = Info->graph[i];
      Info->graph[i].V1 = 0;
      Info->graph[i].V2 = 0;
      Info->graph[i].custo = 0;
      break;
    }
  }
  return save;
}


/******************************************************************************
* CompararMst()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
*            Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: void
*
* Descrição: Procura quais as arestas (caso existam) que repõem a conectividade
*          do grafo
*
*****************************************************************************/
void CompararMst(AirRoutes * Info, MST * mst, MST * mst2, FILE *fout, int variante){
  // variante = 1 -> B1
  // variante = 2 -> C1
  // variante = 3 -> D1
  int count = 0, out = 0, i = 0, j = 0, count_2 = 0;
  int *save_aresta = (int*)calloc(GetMst_TotalEdges(mst)+GetMst_count(mst), sizeof(int));

  for (i = 0; i < GetMst_TotalEdges(mst)+ GetMst_count(mst); i++) {
    for (j = 0; j < GetMst_TotalEdges(mst)+GetMst_count(mst); j++) {
      if ((GetMst_V1(mst2,i) != 0) && (GetMst_V2(mst2,i) != 0)){
        if((GetMst_V2(mst,j)!= 0) && (GetMst_V1(mst,j) != 0)) {
          if ((GetMst_V1(mst,j) == GetMst_V1(mst2,i)) && (GetMst_V2(mst,j) == GetMst_V2(mst2,i))) {
            count++;
            count_2++;
            save_aresta[i] = 1;
            break;
          }
        }
      }
    }
    if (count == 0 && (GetMst_V1(mst2,i) != 0) && (GetMst_V2(mst2,i) != 0) && variante != 3) {
      out = 1;
      break;
    } else count = 0;
  }
  if (out == 0 && variante != 3 && variante!=2) {
    fprintf(fout, " -1\n");
    PrintMst(Info, mst, fout);
  } else {
    if (variante == 1) {
      fprintf(fout, " 1\n");
      PrintMst(Info, mst, fout);
      fprintf(fout,"%d %d %.2lf\n", GetMst_V1(mst2,i), GetMst_V2(mst2,i), GetMstEdge_Custo(mst2, i));
    } else if(variante == 2) {
      fprintf(fout, " %d %.2lf\n",  GetMst_TotalEdges(mst2), GetMst_CustoTotal(mst2));
      PrintMst(Info, mst, fout);
      PrintMst(Info, mst2, fout);
    } else if(variante == 3){
      fprintf(fout," %d\n",  GetMst_TotalEdges(mst2)-count_2);
      PrintMst(Info, mst, fout);
      for (i = 0; i < GetMst_TotalEdges(mst)+ GetMst_count(mst); i++) {
        if (save_aresta[i] != 1 && (GetMst_V1(mst2,i) != 0) && (GetMst_V2(mst2,i) != 0)) {
          fprintf(fout,"%d %d %.2lf\n", GetMst_V1(mst2,i), GetMst_V2(mst2,i), GetMstEdge_Custo(mst2, i));
        }
      }
    }
  }
  free(save_aresta);
}


/******************************************************************************
* CompararMst2()
*
* Argumentos: Info - ponteiro para estrutura de dados do tipo AirRoutes
*            mst - ponteiro para estrutura de dados do tipo MST
             mst2 - ponteiro para estrutura de dados do tipo MST
             fout - ponteiro para ficheiro de saída
             matriz - ponteiro para estrutura de dados do tipo Matriz
* Retorna: void
*
* Descrição: Procura quais as arestas (caso existam) que repõem a conectividade
*          do grafo (para o caso do E1)
*
*****************************************************************************/
void CompararMst2(AirRoutes * Info, MST * mst, MST * mst2, FILE *fout, Matriz * matriz){
  int i = 0, count = 0;
  for (i = 0; i < GetMst_TotalEdges(mst)+ GetMst_count(mst); i++) {
    if ((GetMst_V1(mst2,i) != 0 && GetMst_V2(mst2,i) != 0)) {
      if ((matriz->adj[GetMst_V1(mst2,i)][GetMst_V2(mst2,i)] != '1')) {
        count++;
        break;
      }
    }
  }
  if (count != 0) {
    fprintf(fout," %d %d %.2lf\n", GetMst_V1(mst2,i), GetMst_V2(mst2,i), GetMstEdge_Custo(mst2, i));
  } else fprintf(fout, " -1\n");
}


/******************************************************************************
* RemoveVertice()
*
* Argumentos: mst - ponteiro para estrutura de dados do tipo MST
*            Info - ponteiro para estrutura de dados do tipo AirRoutes
* Retorna: 0 se não existir o vértice
*          1 se encontrar o vértice pretendido
*
* Descrição:
*
*****************************************************************************/
int RemoveVertice(MST * mst, AirRoutes * Info){
  int i = 0, count = 0;

  if (GetInfo_Vertice(Info) <= 0 ) {
    return count;
  }
  i = 0;
    while(i < GetInfo_E(Info)){
      if (GetInfo_GraphV1(Info, i) == GetInfo_Vertice(Info) || GetInfo_GraphV2(Info, i) == GetInfo_Vertice(Info)) {
        count = 1;
        Info->graph[i].V1 = 0;
        Info->graph[i].V2 = 0;
        Info->graph[i].custo = 0;
      }
      i++;
   }
  return count;
}
