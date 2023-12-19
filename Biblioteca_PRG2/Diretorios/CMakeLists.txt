cmake_minimum_required(VERSION 3.23.2)

# Add header files here manually
set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/Diretorios/h/h.h"
)
# Add source files here manually
set(SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/Diretorios/c/c.c"
)

add_library(Diretorios
        c/Arvore.c
        c/ContingSort.c
        c/Fila.c
        c/ListaE.c
        c/ListaL.c
        c/Pilha.c
        c/Tabela.c)
target_sources(c PUBLIC ${SOURCES})
target_include_directories(libprg PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Diretorios/h)

target_compile_features(Biblioteca_PRG2 PUBLIC c_std_17)

# https://cmake.org/cmake/help/latest/prop_tgt/AUTOGEN_TARGETS_FOLDER.html
source_group(
        TREE "${PROJECT_SOURCE_DIR}/Biblioteca_PRG2/Diretorios/h"
        PREFIX "Header Files"
        FILES ${HEADERS})

# https://cmake.org/cmake/help/latest/command/install.html
#install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION h)