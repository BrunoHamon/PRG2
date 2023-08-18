#include "bibli.h"

int main() {

    noh * x = NULL;
    noh * y = NULL;
    int CB[13] = {0};

    messagem_inicial();
    le_vetor(&CB[0]);
    CB_lido(&CB[0]);
    resposta(x, y, &CB[0]);

    return 0;
}