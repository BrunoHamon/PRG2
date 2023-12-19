//
// Created by sjoan on 04/11/2023.
//

#ifndef PROG2_LISTA_ENCADEADA_H
#define PROG2_LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct parametro{
    char *login;
    char *senha;
    char *nome;
} parametro;

typedef struct no{
    int dado;
    char dados[10];
    struct no* proximo;
} no_t;

typedef struct tipo{
    char dados[10];
    char senha[10];
    char nome[30];
} tipo;


void adicionar(no_t** inicio, int dado);
bool remover(no_t** inicio, int dado);
void destruir(no_t** inicio);
int buscar(no_t** inicio, int dado);
int buscar_lista_encadeada(no_t** inicio, char dado[]);
no_t* imprime(no_t** inicio);
int tamanho_no_t (no_t** inicio);

no_t* imprime_string(no_t** inicio);
int adicionar_ordenada(no_t** inicio, int dado);
int remover_ordenada(no_t** inicio, int dado);

void tempo(clock_t start,struct timeval inicio);
void countingSort(int aux[], int n);
int Compara(no_t** inicio,struct tipo parametro);


#endif //PROG2_LISTA_ENCADEADA_H
