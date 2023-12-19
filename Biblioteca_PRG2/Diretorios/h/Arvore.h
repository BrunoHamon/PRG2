//
// Created by aluno on 08/12/23.
//

#ifndef PRG2023_2_ARVORE_H
#define PRG2023_2_ARVORE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct que recebe as entradas
typedef struct usuarios{
    char login[10];
    char senha[10];
    char nome[30];
    int retorno;
}usuarios ;

typedef struct no {
    int valor;
    char valore[10];
    usuarios *us;
    struct no *esquerda;
    struct no *direita;
} no_t;

no_t *criar_no(int valor);
no_t *criar_no_string(usuarios valor);
void destruir_no_arv(no_t *no);
no_t *inserir_valor(no_t *raiz, int valor);
no_t *inserir_valor_string(no_t *raiz, usuarios valor);
bool busca(no_t *raiz, int valor);
bool busca_string(no_t *raiz, usuarios valor);
int busca_str(no_t *raiz, usuarios valor);

#endif //PRG2023_2_ARVORE_H

