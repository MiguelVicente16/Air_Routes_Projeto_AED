/**********************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288)S e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 08/12/2020
*
* NOME
*   GetInfo.h
*
* DESCRIÇÃO
*   Declaração de funções abstratas de obtenção de valores das diferentes estruturas
*
* COMENTÁRIOS
*
**********************************************************************************/

typedef struct AirRoutes AirRoutes;
typedef struct MST MST;
typedef struct Edge Edge;

int GetInfo_V(AirRoutes *);
int GetInfo_E(AirRoutes *);
int GetInfo_Tab(AirRoutes *Info, int coluna, int i);
int GetInfo_Vertice(AirRoutes *Info);
int GetInfo_Vertice_1(AirRoutes *Info);
int GetInfo_Vertice_2(AirRoutes *Info);
double GetMstEdge_Custo(MST * mst, int i);
int GetMst_V1(MST * mst, int i);
int GetMst_V2(MST * mst, int i);
int GetInfo_GraphV1(AirRoutes *Info, int i);
int GetInfo_GraphV2(AirRoutes *Info, int i);
int GetMst_TotalEdges(MST * mst);
int GetMst_count(MST * mst);
double GetMst_CustoTotal(MST * mst);
