#include "b_matrix.h"

#include <stdlib.h>

_Bool ** b_createMatrix(unsigned rows, unsigned cols) {
    _Bool ** mat = malloc(rows * sizeof(_Bool *));
    for(unsigned i = 0; i < rows; i++) {
        mat[i] = malloc(cols * sizeof(_Bool));
    }

    for(unsigned i = 0; i < rows; i++) {
        for(unsigned j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}

void b_deleteMatrix(_Bool ** matrix, unsigned rows) {
    for(unsigned i = 0; i < rows; i++) {
        free((void *) matrix[i]);
    }
    free((void *) matrix);
}

// If unable to multiply matrix, returns a 1x1 matrix with false
_Bool ** b_multMatrix(const _Bool ** matrixA, unsigned rowsA, unsigned colsA,
                      const _Bool ** matrixB, unsigned rowsB, unsigned colsB) {
    if(colsA != rowsB) {
        _Bool ** failed = b_createMatrix(1,1);
        failed[0][0] = 0;
        return failed;
    }

    _Bool ** ret = b_createMatrix(rowsA, colsB);
    for(unsigned i = 0; i < rowsA; i++) {
        for(unsigned j = 0; j < colsB; j++) {
            for(unsigned k = 0; k < colsA; k++) {
                ret[i][j] = ret[i][j] || (matrixA[i][k] && matrixB[k][j]);
            }
        }
    }
    return ret;
}

_Bool ** b_transitiveClosure(const _Bool ** matrix, unsigned n) {
    _Bool ** A = b_copyMatrix(matrix, n,n);
    _Bool ** B = b_copyMatrix(matrix, n,n);
    // b_deleteMatrix in here twice to prevent poor memory management
    for(unsigned i = 0; i < n; i++) {
        _Bool ** aPrime = b_multMatrix((const _Bool **) A, n, n, matrix, n, n);
        b_deleteMatrix(A,n);
        A = b_copyMatrix((const _Bool **)aPrime,n,n);
        B = b_unionMatrix(A, n,n, B, n,n);
        b_deleteMatrix(aPrime, n);
    }
    b_deleteMatrix(A, n);
    return B;
}

_Bool ** b_unionMatrix(_Bool ** matrixA, unsigned rowsA, unsigned colsA,
                       _Bool ** matrixB, unsigned rowsB, unsigned colsB) {
    if(rowsA != rowsB || colsA != colsB) {
        return b_createMatrix(rowsA,colsB);
    }

    _Bool ** unionMat = b_createMatrix(rowsA, colsA);
    for(unsigned i = 0; i < rowsA; i++) {
        for(unsigned j = 0; j < colsB; j++) {
            unionMat[i][j] = matrixA[i][j] || matrixB[i][j];
        }
    }
    return unionMat;
}

_Bool ** b_intersectionMatrix(_Bool ** matrixA, unsigned rowsA, unsigned colsA,
                       _Bool ** matrixB, unsigned rowsB, unsigned colsB) {
    if(rowsA != rowsB || colsA != colsB) {
        return b_createMatrix(rowsA,colsB);
    }

    _Bool ** unionMat = b_createMatrix(rowsA, colsA);
    for(unsigned i = 0; i < rowsA; i++) {
        for(unsigned j = 0; j < colsB; j++) {
            unionMat[i][j] = matrixA[i][j] && matrixB[i][j];
        }
    }
    return unionMat;
}

_Bool ** b_copyMatrix(const _Bool ** original, unsigned rows, unsigned cols) {
    _Bool ** copy = b_createMatrix(rows, cols);
    for(unsigned i = 0; i < rows; i++) {
        for(unsigned j = 0; j < cols; j++) {
            copy[i][j] = original[i][j];
        }
    }
    return copy;
}

_Bool ** b_identityMatrix(unsigned n) {
    _Bool ** identity = b_createMatrix(n, n);
    for(unsigned i = 0; i < n; i++) {
        identity[i][i] = 1;
    }
    return identity;
}