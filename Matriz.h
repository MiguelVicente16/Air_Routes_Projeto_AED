/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288) e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 09/12/2020
*
* NOME
*   Matriz.h
*
* DESCRIÇÃO
*   Declaração das funções de manipulação da matriz de adjacência
*
* COMENTÁRIOS
*
******************************************************************************/
typedef struct Matriz Matriz;
typedef struct MST MST;
typedef struct AirRoutes AirRoutes;
typedef struct Edge Edge;

Matriz *AlocarMatriz(AirRoutes *Info);
void PreencherMatriz(Matriz *matriz, MST * mst);
void FreeMatriz(AirRoutes *Info, Matriz *matriz);
