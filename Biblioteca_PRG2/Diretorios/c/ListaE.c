//
// Created by sjoan on 04/11/2023.
//
#include "../include/Lista_encadeada.h"


void adicionar(no_t** inicio, int dado){
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;
}
// buscar por dados

//BUSCA
int buscar(no_t** inicio, int dado){
    no_t* atuall = *inicio;
    while(atuall != NULL){
        if(atuall->dado == dado){
            return 0;
        }
        else{
            atuall = atuall->proximo;
        }
    }
    return -1;//Valor não existe na lista
}


no_t* imprime(no_t** inicio){
    no_t* atuall = *inicio;
    while(atuall != NULL){
        printf("%d ", atuall->dado);
        atuall = atuall->proximo;
    }
    return 0;
}

no_t* imprime_string(no_t** inicio){
    no_t* atuall = *inicio;
    while(atuall != NULL){
        printf("%s\n", atuall->dados);
        atuall = atuall->proximo;
    }
    return 0;
}

bool remover(no_t** inicio, int dado){
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while(atual != NULL){
        if (atual->dado == dado){
            if (anterior == NULL) {
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

void destruir(no_t** inicio){
    no_t* atual = *inicio;
    no_t* prox;
    while(atual != NULL){
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}

int tamanho_no_t (no_t** inicio){
    if(inicio == NULL)
        return 0;
    int cont = 0;
        no_t* atual = *inicio;
    while (atual != NULL){
        cont ++;
        atual = atual->proximo;
    }
    return cont;
}

int adicionar_ordenada(no_t** inicio, int dado){
    if(inicio == NULL){
        return 0;
    }
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    if(novo == NULL){
        return 0;
    }
    novo->dado = dado;
    if(*inicio == NULL){ // lista vazia
        novo->proximo = NULL;
        *inicio = novo;
        return 1;
    }
    else{
        no_t *anterior, *atual = *inicio;
        while(atual != NULL && atual->dado < dado){
                anterior = atual;
                atual = atual->proximo;
            }
        if(atual == *inicio){ //insere no incio
            novo->proximo = (*inicio);
            *inicio = novo;
        } else{
            novo->proximo = atual;
            anterior->proximo = novo;
        }
        return 1;
    }
}

int Compara(no_t** inicio,struct tipo parametro){
    if(inicio == NULL){
        return 0;
    }
    no_t *novo;
    novo = (no_t*) malloc(sizeof (no_t));

    if(novo == NULL){
        return 0;
    }

    for (int i = 0; i < sizeof(parametro.dados); ++i) {
        novo->dados[i] = parametro.dados[i];
    }

    if((*inicio) == NULL){ // lista vazia
        novo->proximo = NULL;
        *inicio = novo;
        return 1;
    }
    else{
        no_t *anterior, *atual = *inicio;
        while(atual != NULL && strncmp(atual->dados, parametro.dados, sizeof(atual->dados)) < 0){
            anterior = atual;
            atual = atual->proximo;
        }
        if(atual == *inicio){ //insere no incio
            novo->proximo = (*inicio);
            *inicio = novo;
        } else{
            novo->proximo = atual;
            anterior->proximo = novo;
        }
        return 1;
    }
}

int remover_ordenada(no_t** inicio, int dado) {
    if (inicio == NULL) {
        return 0;
    }
    if (*inicio == NULL) { // lista vazia
        return 0;
    }
    no_t  *anterior, *atual = *inicio;
    while (atual != NULL && atual->dado != dado){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL) {
        //Não encontrado
        return 0;
    } else if(atual == *inicio) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
        free(atual);
        return 1;
    }
    return 0;
}

int buscar_lista_encadeada(no_t** inicio, char dado[]) {
        no_t* aux = *inicio;
        while (aux != NULL){
            if (strcmp(aux->dados, dado) == 0) {
                return aux->dado;
            }
            aux = aux->proximo;
        }
    return -1;
}
