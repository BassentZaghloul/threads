#include "print_to_terminal.h"
#include "font_colors.h"
#include "matrix_manipulation.h"

#include<stdio.h>
#include <string.h>


void print_to_console(char* message, char* type) {
    if(!strcmp(type, "error"))
        printf(KRED "%s" KNRM, message);
    if(!strcmp(type, "warning"))
        printf(KYEL "%s" KNRM, message);
}


void print_results_to_console(int threads_number[2], long execution_time[2], bool flag) {
    printf("\n");

    printf(KCYN KBLD " RESULTS:::\n" KNRM);
    printf(" ============\n");


    printf(KCYN KBLD "A] MULTIPLYING ELEMENTS BY CREATING A THREAD FOR EACH ROW:\n" KNRM);
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    if(flag) {
        for(int i = 0; i < dimension_output.x; i++) {
            for(int j = 0; j < dimension_output.y; j++) {
                printf(" %0.3f\t", matrix_output_m1[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf(KCYN "\t1- Number of Threads used = %d threads.\n" KNRM, threads_number[0]);
    printf(KCYN "\t2- Execution Time = %lu microseconds.\n", execution_time[0]);

    printf("\n");

    printf(KCYN KBLD "B] MULTIPLYING ELEMENTS BY CREATING A THREAD FOR EACH ELEMENT:\n" KNRM);
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    if(flag) {
        for(int i = 0; i < dimension_output.x; i++) {
            for(int j = 0; j < dimension_output.y; j++) {
                printf(" %0.3f\t", matrix_output_m2[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf(KCYN "\t1- Number of Threads used = %d threads.\n" KNRM, threads_number[1]);
    printf(KCYN "\t2- Execution Time = %lu microseconds.\n" KNRM, execution_time[1]);
    printf("\n");

}