cmake_minimum_required(VERSION 3.21)

# Add header files here manually
set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/Diretorios/h/libprg/libprg.h"
)
# Add source files here manually
set(SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/Diretorios/c/libprg.c"
)

add_library(libprg
        Diretorios/c/ListaL.c
        Diretorios/c/Fila.c
        Diretorios/c/Pilha.c
        "Diretorios/c/Exercicio _de_pilha.c")
target_sources(libprg PUBLIC ${SOURCES})
target_include_directories(libprg PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Diretorios/h)

target_compile_features(libprg PUBLIC c_std_17)

# https://cmake.org/cmake/help/latest/prop_tgt/AUTOGEN_TARGETS_FOLDER.html
source_group(
       TREE "${PROJECT_SOURCE_DIR}/Biblioteca_PRG2/Diretorios/h"
       PREFIX "Header Files"
       FILES ${HEADERS})

# https://cmake.org/cmake/help/latest/command/install.html
install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include)