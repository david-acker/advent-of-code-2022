#include <stdio.h>

#include "solution.h"

#define TAB "    "

int main(int argc, char** argv) {
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("The specified file does not exist: %s", filename);
        return 1;
    }

    printf("%sPart one: %d\n", TAB, get_signal_marker_index(fp, 5));
    printf("%sPart two: %d\n", TAB, get_signal_marker_index(fp, 14) + 1);

    fclose(fp);

    return 0;
}