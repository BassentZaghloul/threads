#include <stdbool.h>

#ifndef THREADS_MATRIX_MANIPULATION_H
#define THREADS_MATRIX_MANIPULATION_H

/*Holds matrix dimensions.*/
struct matrix_dimension {
    int x;
    int y;
};


struct matrix_dimension dimension_mt1;
struct matrix_dimension dimension_mt2;
struct matrix_dimension dimension_output;

//Assuming matrices could hold doubles.
double** matrix_1;
double** matrix_2;
double** matrix_output_m1;
double** matrix_output_m2;


/*allocates matrices.*/
double** initialize_matrix_with_dim(int row_bound, int column_bound, double** matrix);

/*Frees allocated matrices.*/
void free_matrix_with_dim(int row_bound, int column_bound, double** matrix);

/*fills matrices with values obtained from input file.*/
void set_matrix_values(int row_bound, int column_bound, double** matrix, double** mat);


#endif //THREADS_MATRIX_MANIPULATION_H
