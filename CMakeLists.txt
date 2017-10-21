cmake_minimum_required(VERSION 3.8)
project(threads)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c terminal_messages.c terminal_messages.h font_colors.h print_to_terminal.c print_to_terminal.h file_helper.c file_helper.h run_program.c run_program.h pre_run_setup.c pre_run_setup.h string_parser.c string_parser.h matrix_manipulation.c matrix_manipulation.h string_util.c string_util.h)
add_executable(threads ${SOURCE_FILES} terminal_messages.c terminal_messages.h font_colors.h print_to_terminal.c print_to_terminal.h file_helper.c file_helper.h run_program.c run_program.h pre_run_setup.c pre_run_setup.h string_parser.c string_parser.h matrix_manipulation.c matrix_manipulation.h string_util.c string_util.h)