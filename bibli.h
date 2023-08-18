//
// Created by aluno on 18/08/23.
//

#ifndef UNTITLED_BIBLI_H
#define UNTITLED_BIBLI_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int Ni, Np;
    struct no * aux;
} noh; //tipo de nó

void push(noh ** x, int Ni);
void push2(noh ** y, int Np);
int print(noh * x);
int print2(noh * y);
void messagem_inicial();
void le_vetor(int vet[]);
void CB_lido(int vet[]);
int calc(noh * x, noh * y, int CB[]);
void resposta(noh * x, noh * y, int CB[]);

#endif //UNTITLED_BIBLI_H
