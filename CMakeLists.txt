cmake_minimum_required(VERSION 3.23.2)
project(PRG2 C)

set(CMAKE_C_STANDARD 17)

add_executable(PRG2 main.c
        Biblioteca_PRG2/Diretorios/c/Arvore.c
        Biblioteca_PRG2/Diretorios/c/ContingSort.c
        Biblioteca_PRG2/Diretorios/c/Fila.c
        Biblioteca_PRG2/Diretorios/c/ListaE.c
        Biblioteca_PRG2/Diretorios/c/ListaL.c
        Biblioteca_PRG2/Diretorios/c/Pilha.c
        Biblioteca_PRG2/Diretorios/c/Tabela.c
        Biblioteca_PRG2/Diretorios/h/Arvore.h
        Biblioteca_PRG2/Diretorios/h/ContingSort.h
        Biblioteca_PRG2/Diretorios/h/Fila.h
        Biblioteca_PRG2/Diretorios/h/ListaE.h
        Biblioteca_PRG2/Diretorios/h/ListaL.h
        Biblioteca_PRG2/Diretorios/h/Pilha.h
        Biblioteca_PRG2/Diretorios/h/Tabela.h
)