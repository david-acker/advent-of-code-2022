#include <stdio.h>
#include <stdlib.h>

#include "solution.h"
#include "utils.h"

#define TAB "    "

int main(int argc, char** argv) {
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("The specified file does not exist: %s", filename);
        return 1;
    }

    Input* input = get_input(fp);

    fclose(fp);

    printf("%sPart one: %d\n", TAB, get_sum_of_priorities(input));
    printf("%sPart two: %d\n", TAB, get_sum_of_badge_priorities(input));

    free_input(input);

    return 0;
}
