#include <stdlib.h>
#include <stdio.h>
#include "matrix_manipulation.h"


double** initialize_matrix_with_dim(int row_bound, int column_bound, double** matrix) {
    matrix = (double**) malloc((row_bound) * sizeof(double*));

    for(int i = 0; i < row_bound; i++) {
        matrix[i] = (double*) malloc(column_bound * sizeof(double));
    }
    return matrix;
}


void free_matrix_with_dim(int row_bound, int column_bound, double** matrix) {
    for(int i = 0; i < row_bound; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void set_matrix_values(int row_bound, int column_bound, double** matrix, double** mat) {
    for(int i = 0; i < row_bound; i++) {
        for(int j = 0; j < column_bound; j++) {
            matrix[i][j] = mat[i][j];
        }
    }
    return;
}