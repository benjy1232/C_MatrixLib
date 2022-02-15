cmake_minimum_required(VERSION 3.21)
project(C_Matrix C)

set(CMAKE_C_STANDARD 99)

add_library(C_Matrix b_matrix.h b_matrix.c i_matrix.h i_matrix.c)
