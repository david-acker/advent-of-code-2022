#include <stdio.h>
#include <stdlib.h>

#include "solution.h"

typedef struct inputData {
    int* data;
    int length;
} 
InputData;

InputData* getInputData(FILE* fp);

int main(int argc, char** argv) {
    char* fileName = argv[1];
    FILE* fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("The specified file does not exist: %s", fileName);
        return 1;
    }

    InputData* input = getInputData(fp);

    fclose(fp);

    // Part One
    int partOneResult = getHighestCalories(input->data, input->length);
    printf("Part One: %d\n", partOneResult);

    // Part Two
    int count = 3;
    int partTwoResult = getHighestCombinedCalories(input->data, input->length, count);
    printf("Part Two: %d\n", partTwoResult);

    free(input->data);
    free(input);

    return 0;
}

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