cmake_minimum_required(VERSION 3.28)
project(problemas C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(problemas
        1.1.c
        10.1.1.c
        3.1.1.c
        3.1.2.c
        3.1.3.c
        3.1.4.c
        4.2.2.c
        4.2.4.c
        4.2.6.c
        5.1.3.c
        5.1.5.c
        5.1.8.c
        5.2.2.c
        5.2.4.c
        6.1.5.c
        6.2.1.c
        6.3.1.c
        7.1.1.c
        7.2.1.c
        7.2.2.c
        8.1.1.c
        10.1.1.c
        output/estruturas.h
        exes_felix.c
        filas.c
        misc1.c
        novo1.c
        novo2.c
        pilhas.c
        pontos.c
        pontos.h
        teste.c
        teste_ppp_1.c
        teste_ppp_3.c)
