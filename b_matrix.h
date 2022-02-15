#ifndef C_MATRIX_B_MATRIX_H
#define C_MATRIX_B_MATRIX_H
_Bool ** b_createMatrix(unsigned rows, unsigned cols);
void b_deleteMatrix(_Bool ** matrix, unsigned rows);

_Bool ** b_multMatrix(const _Bool ** matrixA, unsigned rowsA, unsigned colsA,
                      const _Bool ** matrixB, unsigned rowsB, unsigned colsB);

// No error thrown if matrix not square
_Bool ** b_transitiveClosure(const _Bool ** matrix, unsigned n);

_Bool ** b_copyMatrix(const _Bool ** original, unsigned rows, unsigned cols);

_Bool ** b_unionMatrix(_Bool ** matrixA, unsigned rowsA, unsigned colsA,
                       _Bool ** matrixB, unsigned rowsB, unsigned colsB);

_Bool ** b_intersectionMatrix(_Bool ** matrixA, unsigned rowsA, unsigned colsA,
                              _Bool ** matrixB, unsigned rowsB, unsigned colsB);

_Bool ** b_identityMatrix(unsigned n);
#endif //C_MATRIX_B_MATRIX_H
