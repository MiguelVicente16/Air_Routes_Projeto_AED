/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288) e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 04/12/2020
*
* NOME
*   Graph.h
*
* DESCRIÇÃO
*   Declaração das funções que afetam a estrutura graph do tipo edge
*
* COMENTÁRIOS
*
******************************************************************************/

typedef struct AirRoutes AirRoutes;
typedef struct Edge Edge;

void AllocGraph(AirRoutes * Info);
void FillGraph(FILE * fp, AirRoutes * Info);
