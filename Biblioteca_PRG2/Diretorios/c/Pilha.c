//
// Created by aluno on 03/10/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/Pilha.h"

void cria_pilha(pilha_t *pilha, int capacidade){
    pilha->valores = malloc(sizeof (int)*capacidade);
    if(pilha->valores == NULL){
        printf("Falha na alocação de memoria\n");
        exit(1);
    }
    pilha->capacidade =  capacidade;
    pilha->topo = -1;
}
void push(pilha_t *pilha, int x){
        pilha->topo++;
        pilha->valores[pilha->topo] = x;
}
void imprime_pilha(pilha_t *pilha){
    for (int i = pilha->topo; i >= 0; --i) {
        printf("%d ", pilha->valores[i]);
    }
}
int pop(pilha_t *pilha){
    int x;
    x= pilha->valores[pilha->topo];
    pilha->topo--;
    return x;
}

int tamanho_pilha(pilha_t *pilha){
    int tamanho = pilha->capacidade - pilha->topo;
    return tamanho;
}
int vazio_pilha(pilha_t *pilha){
    if (pilha->topo==0){
        return 0;
    }
    else{
        return 1;
    }
}

