#include "pre_run_setup.h"
#include "terminal_messages.h"
#include "print_to_terminal.h"
#include "file_helper.h"
#include "string_parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


bool setup(int argc, char** argv) {
    if(argc != 4) {    //file paths are specified.
        print_to_console(error_message1, "error");
        if(!file_exists(DEF_INPUT_1) || !file_exists(DEF_INPUT_2)) {
            print_to_console(error_message6, "error");
            return false;
        }
        initialize_file_names(DEF_INPUT_1, DEF_INPUT_2, DEF_OUTPUT);
    } else {
        if(!file_exists(argv[1]) || !file_exists(argv[2])) {
            print_to_console(error_message6, "error");
            return false;
        }

        initialize_file_names(argv[1], argv[2], argv[3]);
    }
    dimension_mt1 = extract_matrix_dimension(get_first_line(input_file_name1));
    dimension_mt2 = extract_matrix_dimension(get_first_line(input_file_name2));



    if(dimension_mt1.x <= 0 || dimension_mt1.y <= 0 || dimension_mt2.x <= 0 || dimension_mt2.y <= 0
          || dimension_mt1.y != dimension_mt2.x) {
        print_to_console(error_message3, "error");
        return false;
    }

    dimension_output.x = dimension_mt1.x;
    dimension_output.y = dimension_mt2.y;


    matrix_1 = initialize_matrix_with_dim(dimension_mt1.x, dimension_mt1.y, matrix_1);
    matrix_2 = initialize_matrix_with_dim(dimension_mt2.x, dimension_mt2.y, matrix_2);
    matrix_output_m1 = initialize_matrix_with_dim(dimension_output.x, dimension_output.y, matrix_output_m1);
    matrix_output_m2 = initialize_matrix_with_dim(dimension_output.x, dimension_output.y, matrix_output_m2);



    return (populate_matrix(input_file_name1, dimension_mt1.x, dimension_mt1.y, matrix_1)
                           && populate_matrix(input_file_name2, dimension_mt2.x, dimension_mt2.y, matrix_2));
}


void initialize_file_names(char* input_file1, char* input_file2, char* output_file) {
    input_file_name1 = (char*) malloc (strlen(input_file1) + 1);
    input_file_name2 = (char*) malloc (strlen(input_file2) + 1);

    if(strstr(output_file, ".txt") != NULL) {
        output_file[strlen(output_file) - 4] = '\0';
    }

    output_file_m1 = (char*) malloc (strlen(output_file) + 7); // for _1.out extension.
    output_file_m2 = (char*) malloc (strlen(output_file) + 7); //for _2.out extension

    strcpy(input_file_name1, input_file1);
    strcpy(input_file_name2, input_file2);

    strcpy(output_file_m1, output_file);
    strcpy(output_file_m2, output_file);

    strcat(output_file_m1, "_1.out");
    strcat(output_file_m2, "_2.out");
}


bool populate_matrix(char* filename, int row_bound, int column_bound, double** mat) {
    double** matrix = extract_matrix(filename, row_bound, column_bound);
    if(matrix == NULL){
        return false;
    } else {
        set_matrix_values(row_bound, column_bound, mat, matrix);
        free_matrix_with_dim(row_bound, column_bound, matrix);
        return true;
    }
}