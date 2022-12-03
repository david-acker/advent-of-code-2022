#ifndef UTILS
#define UTILS

#include <stdio.h>

typedef struct inputData {
    int* data;
    int length;
} 
InputData;

InputData* getInputData(FILE* fp);

#endif