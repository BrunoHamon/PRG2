//
// Created by aluno on 27/10/23.
//

#ifndef UNTITLED_LISTA_LINEAR_H
#define UNTITLED_LISTA_LINEAR_H

typedef struct{
    int *valores;
    int tam_max;
    int n_elementos;
}lista_t;

//Lista
void imprime_lista(lista_t *lista);
void cria_lista(lista_t *lista, int tam_max);

//NAO ORDENADAS
void inserir_lista_n_ordenada(lista_t * lista, int x);
int busca_lista_n_ordenada(lista_t *lista, int x);
void remover_lista_n_ordenada(lista_t *lista, int x);

//Ordenadas
int busca_binaria_ordenada(lista_t *lista, int x);
void inserir_lista_ordenada(lista_t * lista, int x);

#endif //UNTITLED_LISTA_LINEAR_H
