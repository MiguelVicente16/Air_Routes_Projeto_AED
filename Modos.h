/******************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288) e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 04/12/2020
*
* NOME
*   Modos.h
*
* DESCRIÇÃO
*   Declaração das funções correspondentes aos modos A1, B1, C1, D1 e E1
*
* COMENTÁRIOS
*
******************************************************************************/

typedef struct AirRoutes AirRoutes;
typedef struct Edge Edge;
typedef struct MST MST;

void ModoA1(FILE *fp, FILE *fout, AirRoutes * Info);
void ModoB1(FILE *fp, FILE *fout, AirRoutes * Info);
void ModoC1(FILE *fp, FILE *fout, AirRoutes * Info);
void ModoD1(FILE *fp, FILE *fout, AirRoutes * Info);
void ModoE1(FILE *fp, FILE *fout, AirRoutes * Info);
