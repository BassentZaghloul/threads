#include <ctype.h>
#include <string.h>
#include "string_util.h"



void copy_strings_p(int p_start, int p_end, char* source_line, char* destination_line) {
    int index, j;
    for(index = 0, j = p_start; j <= p_end; j++, index++) {
            destination_line[index] = source_line[j];
    }
    destination_line[index] = '\0';
}


char* trim_whitespaces(char *str) {
   /* char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator
    *(end+1) = 0;

    return str;*/

    int index, i;

    /*
     * Trim leading white spaces
     */
    index = 0;
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
    {
        index++;
    }

    /* Shift all trailing characters to its left */
    i = 0;
    while(str[i + index] != '\0')
    {
        str[i] = str[i + index];
        i++;
    }
    str[i] = '\0'; // Terminate string with NULL


    /*
     * Trim trailing white spaces
     */
    i = 0;
    index = -1;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            index = i;
        }

        i++;
    }

    /* Mark the next character to last non white space character as NULL */
    str[index + 1] = '\0';
}

bool is_empty_line(char* line) {
    int counter;
    for(counter = 0; counter < strlen(line); counter++) {
        if(line[counter] != ' ' && line[counter] != '\n' && line[counter] != '\t')
            return false;
    }
    return true;
}



