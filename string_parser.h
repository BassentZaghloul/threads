#include "matrix_manipulation.h"

#ifndef THREADS_STRING_PARSER_H
#define THREADS_STRING_PARSER_H


//holds matrix dimensions.
struct matrix_dimension extract_matrix_dimension(char* line);

/*Extract matrix dimensions from input files.*/
double** extract_matrix(char* filename, int row_bound, int column_bound);



#endif //THREADS_STRING_PARSER_H
