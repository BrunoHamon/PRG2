//
// Created by aluno on 29/09/23.
//
#include "/Di"
#include <stdlib.h>
#include <stdio.h>

void cria_fila(fila_t *fila, int capacidade){
    fila->valores = malloc(sizeof (int)*capacidade);
    if(fila->valores == NULL){
        printf("Falha na alocação de memoria\n");
        exit(1);
    }
    fila->capacidade =  capacidade;
    fila->fim = 0;
    fila->inicio=0;
}

void imprime_fila(fila_t *fila){
    for (int i = fila->inicio; i < fila->fim; ++i) {
        printf("%d ", fila->valores[i]);
    }
}

void enfileira(fila_t *fila, int x){
    if(fila->inicio==fila->fim){
        fila->valores[fila->inicio] = x;
        fila->fim++;
    }
    else{
        fila->valores[fila->fim]= x;
        fila->fim++;
    }
}
void desinfileira(fila_t *fila){
        fila->valores[fila->inicio] = 0;
        fila->inicio++;
}
int tamanho(fila_t *fila){
    int tamanho = fila-> capacidade - (fila->fim- fila->inicio);
    return tamanho;
}

void inicio(fila_t *fila) {
    if(tamanho(fila) == fila->capacidade){
        printf("fila esta vazia");
    }
    else{
        printf("O primeiro numero eh %d", fila->valores[fila->inicio]);
    }
}

void fim (fila_t *fila) {
    if(tamanho(fila) == 0){
        printf("fila esta cheia");
    }
    else if (tamanho(fila)== fila->capacidade){
        printf("fila esta vazia");
    }
    else{
        printf("Ultimo numero eh %d", fila->valores[fila->fim-1]);
    }
}

void capacidade(fila_t *fila){
    if(tamanho(fila) == 0){
        printf("fila esta cheia");
    }
    else if (tamanho(fila)== fila->capacidade){
        printf("fila esta vazia");
    }
    else {

    }
}
