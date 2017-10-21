#include <sys/types.h>
#include <pthread.h>
#include "run_program.h"
#include "pre_run_setup.h"
#include "matrix_manipulation.h"
#include "file_helper.h"
#include "print_to_terminal.h"
#include "terminal_messages.h"
#include "font_colors.h"

#include <stdlib.h>
#include <stdio.h>


void run(int argc, char** argv) {

    //Setting up program variables/environment before executing methods.
   if(setup(argc, argv)) {

       int threads_used[2];
       long execution_time[2];

       gettimeofday(&start, NULL);
       threads_used[0] = run_method_1();
       gettimeofday(&stop, NULL);


       execution_time[0] = stop.tv_usec - start.tv_usec;


       gettimeofday(&start, NULL);
       threads_used[1] = run_method_2();
       gettimeofday(&stop, NULL);


       execution_time[1] = stop.tv_usec - start.tv_usec;

       if(threads_used[0] == 0 || threads_used[1] == 0) {
           print_to_console(error_message7,"error");
           free_memory();
           exit(-1);
       }

       /*Prints out results of computing matrices to console.*/
       print_results_to_console(threads_used, execution_time,false);

       if(!write_output_to_file(output_file_m1, matrix_output_m1, dimension_output.x, dimension_output.y, title_message1)
          || !write_output_to_file(output_file_m2, matrix_output_m2, dimension_output.x, dimension_output.y, title_message2)) {
           print_to_console(error_message4, "error");
           print_to_console(warning_message1, "warning");
           /*Special handling if results couldn't be written to an output file.
            * Instead results would be printed out to console.*/
           print_results_to_console(threads_used, execution_time,true);

       }
   } else {
        print_to_console(error_message5, "error");
        free_memory_on_stage_one_error();
        return;
   }
   free_memory();
    return;
}

//a thread computes each row in the output C matrix,
int run_method_1() {
    int thread_creation;
    pthread_t m1_threads[dimension_output.x];



    for(int i = 0; i < dimension_output.x; i++) {
        struct m1_thread *thread_row_index =  malloc(sizeof(struct m1_thread)) ;
         thread_row_index->row = i;
         thread_creation = pthread_create(&m1_threads[i], NULL,  mult_matrix_by_row, (void *)thread_row_index);
        if(thread_creation != 0) {
            perror(KRED "On Creating Threads: ");
            return 0;
        }
    }

    for(int i = 0; i < dimension_output.x; i++) {
        pthread_join(m1_threads[i], NULL);
    }


    return dimension_output.x;
}






// a thread computes each element in the output C matrix.
int run_method_2() {
    pthread_t m2_threads[dimension_output.x * dimension_output.y];
    int index = 0;
    int thread_creation;
    for(int i = 0; i < dimension_output.x; i++) {
        for(int j = 0; j < dimension_output.y; j++) {
            struct m2_thread *thread_element_index = malloc(sizeof(struct m2_thread));
            thread_element_index->row = i;
            thread_element_index->column = j;
           thread_creation = pthread_create(&m2_threads[index], NULL, mult_matrix_by_element, (void *)thread_element_index);
            if(thread_creation != 0) {
                perror(KRED "On Creating Threads: ");
                return 0;
            }
            index++;
        }
    }

    index = 0;
    for(int i = 0; i < dimension_output.x; i++) {
        for(int j = 0; j < dimension_output.y; j++) {
            pthread_join(m2_threads[index], NULL);
            index++;
        }
    }
return (dimension_output.x * dimension_output.y);
}


void* mult_matrix_by_row(void* thread) {
    struct m1_thread *thread_row_index = (struct m1_thread *) thread;
    int row_index = thread_row_index->row;
    int sum = 0;
    for(int i = 0; i < dimension_mt2.y; i++) {
        sum = 0;
        for(int j = 0; j < dimension_mt2.x; j++) {
            sum += matrix_1[row_index][j] * matrix_2[j][i];
        }
        matrix_output_m1[row_index][i] = sum;
    }
    free(thread);
    pthread_exit(0);
}



void* mult_matrix_by_element(void* thread) {
    struct m2_thread *thread_element_index = (struct m2_thread *) thread;

    int i = thread_element_index->row;
    int j = thread_element_index->column;

    int sum = 0;
    for(int k = 0; k < dimension_mt1.y; k++) {
        sum += matrix_1[i][k] * matrix_2[k][j];
    }

    matrix_output_m2[i][j] = sum;
    free(thread);
    pthread_exit(0);
}


void free_memory() {
    free_matrix_with_dim(dimension_mt1.x, dimension_mt1.y, matrix_1);
    free_matrix_with_dim(dimension_mt2.x, dimension_mt2.y, matrix_2);
    free_matrix_with_dim(dimension_output.x, dimension_output.y, matrix_output_m1);
    free_matrix_with_dim(dimension_output.x, dimension_output.y, matrix_output_m2);

    free(output_file_m1);
    free(output_file_m2);
    free(input_file_name1);
    free(input_file_name2);
    return;
}

void free_memory_on_stage_one_error(){
    free(output_file_m1);
    free(output_file_m2);
    free(input_file_name1);
    free(input_file_name2);
    return;
}