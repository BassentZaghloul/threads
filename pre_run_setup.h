#include <stdbool.h>

#ifndef THREADS_PRE_RUN_SETUP_H
#define THREADS_PRE_RUN_SETUP_H

#define DEF_INPUT_1 "a.txt"
#define DEF_INPUT_2 "b.txt"
#define DEF_OUTPUT "c"

char* input_file_name1;
char* input_file_name2;
char* output_file_m1;
char* output_file_m2;


bool setup(int argc, char** argv);


void initialize_file_names(char* input_file1, char* input_file2, char* output_file);


bool populate_matrix(char* filename, int row_bound, int column_bound, double** matrix);

#endif //THREADS_PRE_RUN_SETUP_H
