#ifndef THREADS_RUN_PROGRAM_H
#define THREADS_RUN_PROGRAM_H


#include <sys/time.h>

struct timeval stop, start;

/*A struct holding method one threads' data.*/
struct m1_thread {
    int row;
};

/*A struct holding method two threads' data.*/
struct m2_thread {
    int row;
    int column;
};

/*Runs program.*/
void run(int argc, char** argv);

/*a thread computes each row in the output C matrix,
returns number of threads used to compute the output matrix.*/
int run_method_1();

/*a thread computes each element in the output C matrix,
returns number of threads used to compute the output matrix.*/
int run_method_2();

/*Holds method one algorithm for computing each row of output matrix.*/
void* mult_matrix_by_row(void* thread);

/*Holds method two algorithm for computing each element of output matrix.*/
void* mult_matrix_by_element(void* thread);

/*Frees program memory.*/
void free_memory();

void free_memory_on_stage_one_error();





#endif //THREADS_RUN_PROGRAM_H
