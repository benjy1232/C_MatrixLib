//
// Created by bserrano on 2/14/22.
//

#ifndef C_MATRIX_I_MATRIX_H
#define C_MATRIX_I_MATRIX_H

int ** i_createMatrix(unsigned rows, unsigned cols);
void i_deleteMatrix(int ** matrix, unsigned rows);

int ** i_addMatrix(int ** matrixA, unsigned rowsA, unsigned  colsA,
                   int ** matrixB, unsigned rowsB, unsigned colsB);

int ** i_subMatrix(int ** matrixA, unsigned rowsA, unsigned  colsA,
                   int ** matrixB, unsigned rowsB, unsigned colsB);

int ** i_multMatrix(int ** matrixA, unsigned rowsA, unsigned  colsA,
                    int ** matrixB, unsigned rowsB, unsigned colsB);
#endif //C_MATRIX_I_MATRIX_H
