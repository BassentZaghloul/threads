#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "string_parser.h"
#include "string_util.h"
#include "print_to_terminal.h"
#include "terminal_messages.h"


struct matrix_dimension extract_matrix_dimension(char* line) {

    trim_whitespaces(line);

    bool dim = false;
    bool set_x = true;

    int start_p = -1;
    int end_p = 0;
    struct matrix_dimension dimension;
    int i;





    for(i = 0; line[i] != '\0' && i < strlen(line); i++) {
        if(line[i] == '=') {
            dim = true;
            start_p = i + 1;
        } else if(dim && !isdigit(line[i])) {
            end_p = i - 1;
            char *temp = (char *) malloc(end_p - start_p + 1 + 1);
            copy_strings_p(start_p, end_p, line, temp);

            /* atoi: This function returns the converted integral number as an int value.
              * If no valid conversion could be performed, it returns zero.*/
            if (set_x)
                dimension.x = atoi(temp);
            else
                dimension.y = atoi(temp);
            set_x = false;
            dim = false;
            start_p = -1;
            free(temp);
        }
    }

    if(dim && i > 0 && isdigit(line[i - 1])) {
        end_p = i - 1;
        char* temp = (char*) malloc(end_p - start_p + 1 + 1);
        copy_strings_p(start_p, end_p, line, temp);

        if(set_x)
            dimension.x = atoi(temp);
        else
            dimension.y = atoi(temp);
        free(temp);
    }

    free(line);
    return dimension;
}



double** extract_matrix(char* filename, int row_bound, int column_bound) {

    char matrix_line [513];
    //matrix_line[0] =(int *) NULL;
    double** matrix;
    int row_count = 0;
    int col_count = 0;
    matrix = initialize_matrix_with_dim(row_bound, column_bound, matrix);


    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        print_to_console(error_message2, "error");
        return NULL;
    } else {
        while(fgets(matrix_line, 513, in) != NULL) {
            if(is_empty_line(matrix_line) || (strchr(matrix_line,'=') != NULL)) {
                continue;
            }
            col_count = 0;
            if(row_count >= row_bound) {
                free_matrix_with_dim(row_bound, column_bound, matrix);
                fclose(in);
                return NULL;
            }
            trim_whitespaces(matrix_line);
            const char s[2] = "\t";
            char *token;

           //  get the first token
            token = strtok(matrix_line, s);

           //  walk through other tokens
            while( token != NULL ) {
                if(col_count >= column_bound) {
                    free_matrix_with_dim(row_bound, column_bound, matrix);
                    fclose(in);
                    return NULL;
                }

                matrix[row_count][col_count] = atof(token);
                col_count++;
                token = strtok(NULL, s);
            }

            if(col_count != column_bound) {

                free_matrix_with_dim(row_bound, column_bound, matrix);
                fclose(in);
                return NULL;
            }
            row_count++;
        }
        fclose(in);


        if(row_count != row_bound) {
            free_matrix_with_dim(row_bound, column_bound, matrix);
            return NULL;
        }
        return matrix;
    }

}