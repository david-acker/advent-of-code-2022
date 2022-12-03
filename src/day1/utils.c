#include <stdio.h>
#include <stdlib.h>

typedef struct inputData {
    int* data;
    int length;
} 
InputData;

InputData* getInputData(FILE* fp) {
    fseek(fp, 0, SEEK_SET);

    int* data = malloc(0);

    char line[10];
    int index = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        data = realloc(data, sizeof(int) * (index + 1));

        data[index] = atoi((char*)line);
        
        index++;
    }

    InputData* inputData = malloc(sizeof(InputData));
    inputData->data = data;
    inputData->length = index;

    return inputData;
}