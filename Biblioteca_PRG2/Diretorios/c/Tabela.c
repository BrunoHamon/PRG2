//
// Created by aluno on 21/11/23.
//
#include "../include/tabela.h"



dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    if (m < 1) {
        return NULL;
    }
    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL) {
        return NULL;
    }
// O calloc já deve colocar NULL, mas deixo aqui de forma explícita
    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa) {
    if (pessoa->a != NULL) {
        free(pessoa->a);
    }
    if (pessoa->b != NULL) {
        free(pessoa->b);
    }
    if (pessoa->c != NULL) {
        free(pessoa->c);
    }
    free(pessoa);
}
void destruir_no(no_t *no) {
    if (no != NULL) {
        free(no->chave);
        destruir_pessoa(no->valor);
        free(no);
    }
}

void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
    //TODO destruir lista encadeada
    destruir_no(d->vetor[i]);
    }
    free(d->vetor);
    free(d);
    }
}
// método por divisão com chave alfanumérica
int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
    soma += (i + 1) * chave[i];
    }
return soma % m;
}

bool inserir_Lista_encadeada(dicionario_t *d, char *chave, pessoa_t *valor) {
    int indice = hash(chave, d->tamanho);
    no_t *no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }
    // strdup reserva memória para fazer a cópia da string. Presente em string.h padrão
    // C23 https://en.cppreference.com/w/c/string/byte/strdup
    no->chave = strdup(chave);
    if (no->chave == NULL) {
       free(no);
        return false;
    }

    no->valor = valor;
    no->prox = NULL;

    if(d->vetor[indice] == NULL){
        d->vetor[indice] = no;
    }
    else{
        no_t *aux;
        aux = d->vetor[indice];
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
return true;
}

pessoa_t *buscar_hash(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    if (d->vetor[indice] != NULL) {
        if (strcmp(d->vetor[indice]->chave, chave) == 0) {
            return d->vetor[indice]->valor;
        }
    }
    return NULL;
}

void imprimir_pessoa_Lista_encadeada(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar_hash_lista_encadeada(d, chave);
    if (p != NULL) {
        printf("%s\t  %s\t  %s\n", p->a, p->b, p->c);
    } else {
        printf("%s não encontrada\n", chave);
    }
}

void imprimir_pessoa(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar_hash(d, chave);
    if (p != NULL) {
        printf("%s\t  %s\t  %s\n", p->a, p->b, p->c);
    } else {
        printf("%s não encontrada\n", chave);
    }
}

char * copia_string(char *s) {
    char *copia = malloc(sizeof(char) * (strlen(s) + 1));
    if (copia == NULL) {
        return NULL;
    }
    strcpy(copia, s);
    return copia;
}

void destruir_dicionario_lista_encadeada(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
            no_t* atual = d->vetor[i];
            no_t* prox;
            while(atual != NULL){
                prox = atual->prox;
                destruir_no(atual);
                atual = prox;
            }
            *d->vetor = NULL;
        }
        free(d->vetor);
        free(d);
    }
}

bool inserir(dicionario_t *d, char *chave, pessoa_t *valor) {
    int indice = hash(chave, d->tamanho);
    no_t *no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }
    // strdup reserva memória para fazer a cópia da string. Presente em string.h padrão
    // C23 https://en.cppreference.com/w/c/string/byte/strdup
    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return false;
    }

        no->valor = valor;
        no->prox = NULL;

    // libera a memória se existir um nó anterior na posição
    destruir_no(d->vetor[indice]);
    d->vetor[indice] = no;
    return true;
}

pessoa_t *buscar_hash_lista_encadeada(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    if (d->vetor[indice] != NULL) {
        no_t *aux;
        aux = d->vetor[indice];
        while (aux != NULL){
            if (strcmp(aux->chave, chave) == 0) {
                return aux->valor;
            }
            aux = aux->prox;
        }
    }
    return NULL;
}
