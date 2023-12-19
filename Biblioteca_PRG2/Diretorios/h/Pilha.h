//
// Created by aluno on 27/10/23.
//

#ifndef UNTITLED_PILHA_H
#define UNTITLED_PILHA_H

typedef struct{
    int *valores;
    int topo;
    int capacidade;
}pilha_t;


//Pilha
void cria_pilha(pilha_t *fila, int capacidade);
void imprime_pilha(pilha_t *pilha);
void push(pilha_t *pilha, int x);
int pop(pilha_t *pilha);
int tamanho_pilha(pilha_t *pilha);
int vazio_pilha(pilha_t *pilha);
int Notacao(int argc, char *argv[]);


#endif //UNTITLED_PILHA_H
