//
// Created by Joana on 19/09/23.
//
#include "../include/Lista_linear.h"
#include <stdlib.h>
#include <stdio.h>


void cria_lista(lista_t *lista, int tam_max){
    lista->valores = malloc(sizeof (int)*tam_max);
    if(lista->valores == NULL){
        printf("Falha na alocação de memoria\n");
        exit(1);
    }
    lista->tam_max =  tam_max;
    lista->n_elementos = 0;
}


//NÃO ORDENADASSSSSSS
int busca_lista_n_ordenada(lista_t *lista, int x){
    int i;
    for ( i = 0; i < lista->n_elementos; ++i) {
        if(x==lista->valores[i]){
            return 0;
        }
    }
    return x;
}

void inserir_lista_n_ordenada(lista_t * lista, int x){
    if(busca_lista_n_ordenada(lista,x)) {
        lista->valores[lista->n_elementos]= x;
        lista->n_elementos ++;
    }
}

void remover_lista_n_ordenada(lista_t *lista, int x) {
    for (int i = 0; i < lista->n_elementos; ++i) {
        if (x == lista->valores[i]) {
            lista->valores[i] = lista->valores[lista->n_elementos - 1];
            lista->n_elementos--;
        }
    }
}



void imprime_lista(lista_t *lista){
    for (int i = 0; i < lista->n_elementos; ++i) {
        printf("%d\n", lista->valores[i]);
    }
}


int busca_binaria_ordenada(lista_t *lista, int x){
    int inicio = 0;
    int meio;
    int fim = lista->n_elementos;
    while (inicio <= fim){
        meio =  inicio + (fim- inicio)/2;
        if(lista->valores[meio] == x){
            return 0;
        } else if(lista->valores[meio]< x){
            inicio = meio + 1;
        }
        else {
            fim = meio -1;
        }
    }
    return meio;
}

void inserir_lista_ordenada(lista_t * lista, int x){
    int r = 0;
    if (busca_binaria_ordenada(lista,x)){
        for (int i = lista->n_elementos; i > busca_binaria_ordenada(lista,x); --i) {
            lista->valores[i] = lista->valores[i-1];
            r++;
        }
        lista->valores[lista->n_elementos-r]= x;
    }else{
        printf("Numero ja existe");
    }
}

void remover_lista_ordenada(lista_t *lista, int x){
    if (busca_binaria_ordenada(lista,x)){
        printf("Numero nao ja existe");
    }else{

}
}
