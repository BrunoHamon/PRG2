//
// Created by aluno on 27/10/23.
//

#ifndef UNTITLED_FILA_LINEAR_H
#define UNTITLED_FILA_LINEAR_H

typedef struct {
    int *valores;
    int inicio;
    int fim;
    int capacidade;
}fila_t;

//Fila
void imprime_fila(fila_t *fila);
void cria_fila(fila_t *fila, int capacidade);

//
void enfileira(fila_t *fila, int x);
void desinfileira(fila_t *fila);
void inicio(fila_t *fila);
int tamanho(fila_t *fila);
void fim(fila_t *fila);
void capacidade(fila_t *fila);

#endif //UNTITLED_FILA_LINEAR_H
