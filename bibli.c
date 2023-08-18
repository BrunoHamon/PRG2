//
// Created by aluno on 18/08/23.
//

#include "bibli.h"

void push(noh ** x, int Ni){
    noh * i;
    i = (noh *) malloc(sizeof (noh));

    i-> Ni = Ni;
    i-> aux = *x;
    *x = i;
}

void push2(noh ** y, int Np){
    noh * i;
    i = (noh *) malloc(sizeof (noh));

    i-> Np = Np;
    i-> aux = *y;
    *y = i;
}

int print(noh * x){
    int Valor = 0 ;
    noh * i = x;
    while (i !=NULL){
        Valor = Valor+ i-> Ni;
        i= i -> aux;
    }
    return Valor;
}

int print2(noh * y){
    int Valor = 0 ;
    noh * i = y;
    while (i !=NULL){
        Valor = Valor+ i-> Np;
        i= i -> aux;
    }
    return Valor;
}

void messagem_inicial() {
    printf("Entre com o codigo de barras: ");
}

void le_vetor(int vet[]) {
    int i;
    for (i = 0; i < 13; ++i) {
        scanf("%1d", &vet[i]);
    }
}

void CB_lido(int vet[]) {
    for (int i = 0; i < 13; ++i) {
        printf("%d", vet[i]);
    }
    printf("\n");
}

int calc(noh * x, noh * y, int CB[]) {
    for (int i = 0; i < 12; ++i) {
        if((i % 2)==0){
            push(&x,CB[i]);
        } else{
            push2(&y,CB[i]);
        }
    }

    int Par = print2(y);
    int Impar = print(x);

    Par = (Par*3);
    Par = Par + Impar-1;
    Par = Par % 10;
    Par = 9 - Par;

    return Par;
}

void resposta(noh * x, noh * y, int CB[]) {
    if(calc(x, y, &CB[0]) == CB[12]){
        printf("CODIGO VALIDO");
    } else{
        printf("CODIGO INVALIDO");
    }
}