/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288) e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 04/12/2020
*
* NOME
*   ManipularMST.h
*
* DESCRIÇÃO
*    Declaração das funções que permitem manipular e trabalhar com uma MST
*   previamente determinada
*
* COMENTÁRIOS
*
******************************************************************************/
typedef struct AirRoutes AirRoutes;
typedef struct Edge Edge;
typedef struct MST MST;
typedef struct Matriz Matriz;

void PrintMst(AirRoutes * Info, MST * mst, FILE * fout);
int FindEdgemst(MST * mst, AirRoutes * Info);
int FindEdgeGraph(MST * mst, AirRoutes * Info);
Edge FindEdgeGraph2(MST * mst, AirRoutes * Info);
void CompararMst(AirRoutes * Info, MST * mst, MST * mst2, FILE *, int);
void CompararMst2(AirRoutes * Info, MST * mst, MST * mst2, FILE *fout, Matriz * matriz);
int RemoveVertice(MST * mst, AirRoutes * Info);
