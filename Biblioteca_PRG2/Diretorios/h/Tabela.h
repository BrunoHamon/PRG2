//
// Created by aluno on 21/11/23.
//

#ifndef PRG2023_2_TABELA_H
#define PRG2023_2_TABELA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    char *b;
    char *c;
} pessoa_t;

typedef struct no {
    char *chave;
    pessoa_t *valor;
    struct no *prox;
} no_t;

typedef struct dicionario {
    int tamanho; // tamanho do vetor
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m);
void destruir_pessoa(pessoa_t *pessoa);
void destruir_no(no_t *no);
void destruir_dicionario(dicionario_t *d);
int hash(const char *chave, int m);
bool inserir(dicionario_t *d, char *chave, pessoa_t *valor);
pessoa_t *buscar_hash(dicionario_t *d, char *chave);
void imprimir_pessoa(dicionario_t *d, char *chave);
char * copia_string(char *s);
void destruir_dicionario_lista_encadeada(dicionario_t *d);
bool inserir_Lista_encadeada(dicionario_t *d, char *chave, pessoa_t *valor);
pessoa_t *buscar_hash_lista_encadeada(dicionario_t *d, char *chave);
void imprimir_pessoa_Lista_encadeada(dicionario_t *d, char *chave);
#endif //PRG2023_2_TABELA_H
