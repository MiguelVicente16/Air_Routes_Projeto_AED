/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288) e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 04/12/2020
*
* NOME
*   EncontrarMST.h
*
* DESCRIÇÃO
*   Declaração das funções que permitem identificar a MST do grafo
*
* COMENTÁRIOS
*
******************************************************************************/

typedef struct AirRoutes AirRoutes;
typedef struct Edge Edge;
typedef struct MST MST;
typedef struct subgrafo subgrafo;

MST * KruskalMST(AirRoutes * Info, MST * mst);
int Compare_1(const void* a, const void* b);
int Compare_2(const void* a, const void* b);
int Compare_3(const void* a, const void* b);
int FindMst(subgrafo *, int i);
void Union(subgrafo *, int x, int y);
