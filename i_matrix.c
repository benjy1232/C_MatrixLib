#include "i_matrix.h"

#include <stdlib.h>

int ** i_createMatrix(unsigned rows, unsigned cols) {
    int ** mat = malloc(rows * sizeof(int*));
    for(unsigned i = 0; i < rows; i++) {
        mat[i] = malloc(cols * sizeof(int));
        for(unsigned j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}

void i_deleteMatrix(int ** mat, unsigned rows) {
    for(unsigned i = 0; i < rows; i++) {
        free((void *)mat[i]);
    }
    free((void *) mat);
}

int ** i_addMatrix(int ** matrixA, unsigned rowsA, unsigned  colsA,
                   int ** matrixB, unsigned rowsB, unsigned colsB) {
    if(rowsA != rowsB || colsA != colsB) {
        return i_createMatrix(rowsA, colsB);
    }
    int ** result = i_createMatrix(rowsA, rowsB);

    for(int i = 0; i < rowsA; i++) {
        for(unsigned j = 0; j < colsB; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int ** i_subMatrix(int ** matrixA, unsigned rowsA, unsigned  colsA,
                   int ** matrixB, unsigned rowsB, unsigned colsB) {
    if(rowsA != rowsB || colsA != colsB) {
        return i_createMatrix(1, 1);
    }
    int ** result = i_createMatrix(rowsA, rowsB);

    for(int i = 0; i < rowsA; i++) {
        for(unsigned j = 0; j < colsB; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

int ** i_multMatrix(int ** matrixA, unsigned rowsA, unsigned  colsA,
                    int ** matrixB, unsigned rowsB, unsigned colsB) {
    if(colsA != rowsB) {
        return i_createMatrix(1,1);
    }

    int ** result = i_createMatrix(rowsA, colsB);
    for(unsigned i = 0; i < rowsA; i++) {
        for(unsigned j = 0; j < colsB; j++) {
            for(unsigned k = 0; k < colsA; k++) {
                result[i][j] = result[i][j] + (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }
    return matrixA;
}