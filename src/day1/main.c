#include <stdio.h>
#include <stdlib.h>

#include "solution.h"
#include "utils.h"

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
