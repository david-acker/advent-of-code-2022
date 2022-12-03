#include <stdio.h>
#include <stdlib.h>

#include "solution.h"
#include "utils.h"

#define TAB "    "

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
    printf("%sPart One: %d\n", TAB, partOneResult);

    // Part Two
    int count = 3;
    int partTwoResult = getHighestCombinedCalories(input->data, input->length, count);
    printf("%sPart Two: %d\n", TAB, partTwoResult);

    free(input->data);
    free(input);

    return 0;
}
