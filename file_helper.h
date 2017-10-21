#ifndef THREADS_FILE_HELPER_H
#define THREADS_FILE_HELPER_H

#include <stdbool.h>

/* Checks whether the specified file exists.*/
bool file_exists(const char *filename);

/*Clears file contents.
 * Returns true if succeeded, false otherwise.*/
bool clear_file_content(const char *filename);

/*Initializes output file.
 * Creates it if it doesn't exist.*/
void initialize_output_file(const char*filename);

/*Writes to output file specified.*/
bool write_to_file(const char* filename, char* matrix_line);

/*reads file specified,
 * returns NULL if can no longer read file.*/
char* get_first_line(char* filename);

/*Writes results to output file.*/
bool write_output_to_file(char* filename, double** matrix, int row_bound, int column_bound, char* message);






#endif //THREADS_FILE_HELPER_H
