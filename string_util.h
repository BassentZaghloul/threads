#ifndef THREADS_STRING_UTIL_H
#define THREADS_STRING_UTIL_H

#include <stdbool.h>

/*Copy strings from source to destination,
 * using pointers to specify start and end.*/
void copy_strings_p(int p_start, int p_end, char* source_line, char* destination_line);

// Note: This function returns a pointer to a substring of the original string.
// If the given string was allocated dynamically, the caller must not overwrite
// that pointer with the returned value, since the original pointer must be
// deallocated using the same allocator with which it was allocated.  The return
// value must NOT be deallocated using free() etc.
char *trim_whitespaces(char *str);

/*Checks whether line is empty/is of white spaces only.*/
bool is_empty_line(char* line);




#endif //THREADS_STRING_UTIL_H
