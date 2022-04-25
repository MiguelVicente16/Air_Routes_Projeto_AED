/*******************************************************************************************
* (c) Novembro-Dezembro 2020 Miguel Vicente (96288) e Marta Bárbolo (96281)
* Projeto Final AirRoutes para a UC Algoritmos e Estruturas de Dados
* Última alteração: 04/12/2020
*
* NOME
*   main.c
*
* DESCRIÇÃO
*    Função main - self explanatory
*    Função VerificarModo - Determinação da variante a resolver
*    Função OpenOutFile - Abertura do ficheiro de saída com a correta extensão
*    Função FillNumberRoutes - Preenchimento do número de arestas (retirado do ficheiro de entrada)
*                           no campo correspondente da Estrutura
*    Função FillNumberAirports - Preenchimento do número de vértices (retirado do ficheiro de entrada)
*                           no campo correspondente da estrutura
*
* COMENTÁRIOS
*
*
******************************************************************************************/
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
#include "Modos.h"

typedef struct Edge {
  int V1, V2;
  double custo;
} Edge;

typedef struct AirRoutes {
  int v, e, vertice_1, vertice_2, vertice, count;
  struct Edge* graph;
}AirRoutes;


/***************************************************************************
* VerificarExtensao ()
*
* Argumentos: argv - ponteiro para vetor de string que contém os argumentos
*                   passados na chamada do programa
* Retorna: void
*
* Descrição: verifica que a extensão do ficheiro introduzido é a correta
*
***************************************************************************/
void VerificarExtensao (char *argv[]){
  const char lookfor = '.';
  char *point;
  point = strrchr(argv[1], lookfor);
  if ((*(point+1) != 'r') || (*(point+2) != 'o') || (*(point+3) != 'u')
  || (*(point+4) != 't') ||  (*(point+5) != 'e') ||  (*(point+6) != 's')
  || (*(point+7) != '\0')) {
    exit(0);
  }
  return;
}

/******************************************************************************
 * OpenOutFile()
 *
 * Argumentos: filename - string com o nome do ficheiro de entrada
 * Retorna: ponteiro para o ficheiro de saída
 *
 * Descrição: Abertura do ficheiro de saída com a correta extensão
 *
 *****************************************************************************/
FILE *OpenOutFile(char *filename){
  char *aux, *out_name;
  FILE *fout;
  int i = 0;
  out_name = (char*) calloc ((strlen(filename) - 6) , sizeof(char));
  int size = 0 ;
  int save = 0;
  size = strlen(filename);
  while (i != size) {
    if (filename[i] == '.') {
      save = i;
    }
    i++;
  }
  i = 0;
  while (i != save) {
    out_name[i] = filename[i];
    i++;
  }
  aux = (char *) calloc((strlen(out_name) + strlen(".bbones") + 1) , sizeof(char));
  strcpy(aux, out_name);
  strcat(aux, ".bbones");
  fout = fopen(aux, "w");
  if (fout == NULL) {
    exit(0);
  }
  free(aux);
  free(out_name);
  return fout;
}

/******************************************************************************
 * FillNumberAirports()
 *
 * Argumentos: Info - ponteiro para estrutura de dados
 *             fp - ponteiro para o ficheiro de entrada
 * Retorna: void
 *
 * Descrição: Preenchimento do número de vértices (retirado do ficheiro de entrada)
 *           no campo correspondente da estrutura
 *
 *****************************************************************************/
void FillNumberAirports(AirRoutes* Info, FILE *fp) {
  if(fscanf(fp, "%d ", &Info->v) != 1){
  }
}

/******************************************************************************
 * FillNumberRoutes()
 *
 * Argumentos: Info - ponteiro para estrutura de dados
 *             fp - ponteiro para o ficheiro de entrada
 * Retorna: void
 *
 * Descrição: Preenchimento do número de arestas (retirado do ficheiro de entrada)
 *            no campo correspondente da Estrutura
 *
 *****************************************************************************/
void FillNumberRoutes(AirRoutes* Info, FILE *fp) {
  if(fscanf(fp, "%d ", &Info->e) != 1){
  }
}

/******************************************************************************
 * VerificarModo()
 *
 * Argumentos: fp - ponteiro para o ficheiro de entrada
 *             filename - string com o nome do ficheiro de entrada
 *             Info - ponteiro para estrutura de dados
 * Retorna: void
 *
 * Descrição: Determinação da variante a resolver
 *
 *****************************************************************************/
void VerificarModo(FILE * fp, char *filename, AirRoutes * Info){
  char variante[2];
  FILE *fout;
  fout = OpenOutFile(filename);
  while (!feof(fp)) {
    variante[0] = '-' ; Info->v = -1; Info->e = -1;
    FillNumberAirports(Info, fp);
    FillNumberRoutes(Info, fp);
    if(fscanf(fp, "%c %c", &variante[0], &variante[1]) != 2){
    }
    if (variante[0] != '-' && GetInfo_V(Info) != -1 && GetInfo_E(Info)!=-1 ) {
      if (strcmp("A1", variante) == 0) {
        fprintf(fout, "%d %d %c%c", GetInfo_V(Info), GetInfo_E(Info), variante[0], variante[1]);
        ModoA1(fp, fout, Info);
      } else if (strcmp("B1", variante) == 0) {
        if(fscanf(fp, "%d %d", &Info->vertice_1, &Info->vertice_2) != 2){
        }
        fprintf(fout, "%d %d %c%c %d %d", GetInfo_V(Info), GetInfo_E(Info), variante[0], variante[1],Info->vertice_1, Info->vertice_2);
        ModoB1(fp, fout,  Info);
      } else if (strcmp("C1", variante) == 0) {
        if(fscanf(fp, "%d %d", &Info->vertice_1, &Info->vertice_2) != 2){
        }
        fprintf(fout, "%d %d %c%c %d %d", GetInfo_V(Info), GetInfo_E(Info), variante[0], variante[1],Info->vertice_1, Info->vertice_2);
        ModoC1(fp, fout,  Info);
      } else if (strcmp("D1", variante) == 0) {
         Info->vertice = 0;
        if(fscanf(fp, "%d", &Info->vertice) != 1){
        }
        fprintf(fout, "%d %d %c%c %d", GetInfo_V(Info), GetInfo_E(Info), variante[0], variante[1], Info->vertice);
        ModoD1(fp, fout,  Info);
      } else if (strcmp("E1", variante) == 0) {
        fprintf(fout, "%d %d %c%c ", GetInfo_V(Info), GetInfo_E(Info), variante[0], variante[1]);
        ModoE1(fp, fout,  Info);
        }
    }
  }
  fclose(fout);
  return;
}


/******************************************************************************
 * main()
 *
 * Argumentos: argc - número de argumentos passados na chamada do programa
 *             argv - ponteiro para vetor de string que contém os argumentos
 *                   passados na chamada do programa
 * Retorna: 0
 *
 * Descrição: self explanatory
 *
 *****************************************************************************/
int main(int argc, char *argv[]) {
  FILE *fp;
  char *filename = argv[1];
  AirRoutes Info;
  fp = (FILE *) fopen(argv[1], "r");
  if (fp == NULL) {
    exit (0);
  }
  VerificarExtensao(argv);
  VerificarModo(fp, filename, &Info);
  fclose(fp);

  return 0;
}
