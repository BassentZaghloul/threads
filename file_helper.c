#include <stdio.h>
#include <stdlib.h>
#include "file_helper.h"
#include "font_colors.h"
#include "terminal_messages.h"
#include "print_to_terminal.h"
#include "string_util.h"


bool file_exists(const char *filename) {
    FILE* file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return true;
    }
    return false;
}


bool clear_file_content(const char *filename) {
    FILE* file;
    if(file = fopen(filename, "w")) {
        fclose(file);
        return true;
    }
    return false;
}



void initialize_output_file(const char* filename) {
    FILE *fp = fopen(filename, "ab+");
    fclose(fp);
}





bool write_to_file(const char* filename, char* matrix_line) {
    FILE *output = fopen(filename, "w");
    if (output != NULL) {
        fclose(output);
        return true;
    } else {
        perror(KRED "ERROR: On writing to output file: " KNRM);
        return false;
    }
}







char* get_first_line(char* filename) {
    char *matrix_line = (char*) malloc(100);
    matrix_line[0] = NULL;
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        print_to_console(error_message2, "error");
    } else {
       while(fgets(matrix_line, 100, in) != NULL && is_empty_line(matrix_line));
    }
    fclose(in);
    return matrix_line;
}

bool write_output_to_file(char* filename, double** matrix, int row_bound, int column_bound, char* message) {
    FILE *output = fopen(filename, "w");
    if (output != NULL) {
        if(message != NULL)
            fprintf(output,"%s", message);
        for(int i = 0; i < row_bound; i++) {
            for(int j = 0; j < column_bound; j++) {
                fprintf(output, "%0.3f\t", matrix[i][j]);
            }
            fprintf(output, "\n");
        }
        fclose(output);
        return true;
    } else {
        perror(KRED "ERROR: On writing to output file: " KNRM);
        return false;
    }
}