#ifndef UTILS
#define UTILS

#include <stdio.h>

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

Input* get_input(FILE* fp);

#endif