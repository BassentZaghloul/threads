#ifndef THREADS_PRINT_TO_TERMINAL_H
#define THREADS_PRINT_TO_TERMINAL_H

#include <stdbool.h>

/*prints out information/error messages to the console.*/
void print_to_console(char* message, char* type);

void print_results_to_console(int threads_number[2], long execution_time[2], bool flag);
#endif //THREADS_PRINT_TO_TERMINAL_H
