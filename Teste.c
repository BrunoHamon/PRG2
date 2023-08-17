#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int Ni, Np;
    struct no * aux;
} noh; //tipo de nó


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


int main() {

    noh * x = NULL;
    noh * y = NULL;

    int CB[13] = {0};

    printf("Entre com o codigo de barras: ");

    for (int i = 0; i < 13; ++i) {
        scanf("%1d", &CB[i]);
    }

    for (int i = 0; i < 13; ++i) {
        printf("%d", CB[i]);
    }

    printf("\n");

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

    if(Par == CB[12]){
        printf("CODIGO VALIDO");
    } else{
        printf("Codigo invalido");
    }

    return 0;
}
