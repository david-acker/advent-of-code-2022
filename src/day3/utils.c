#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct InputRow {
    char* data;
    int length;
}
InputRow;

typedef struct Input {
    InputRow** rows;
    int length;
}
Input;

Input* get_input(FILE* fp) {
    fseek(fp, 0, SEEK_SET);
    
    InputRow** rows = malloc(0);

    int buffer_length = 70;
    char* buffer = calloc(buffer_length, sizeof(char));

    int index = 0;
    while (fgets(buffer, (buffer_length * sizeof(char)), fp) != NULL) {
        
        int length = strlen(buffer);
        if (buffer[length - 1] == '\n') {
            length--;
        }

        char* line = malloc(length);
        memcpy(line, buffer, length);

        InputRow* row = malloc(sizeof(InputRow));
        row->data = line;
        row->length = length;

        rows = realloc(rows, sizeof(InputRow) * (index + 1));
        rows[index] = row;

        index++;

        memset(buffer, '\0', sizeof(char));
    }

    free(buffer);

    Input* input = malloc(sizeof(Input));
    input->rows = rows;
    input->length = index;

    return input;
}