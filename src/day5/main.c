#include <stdio.h>
#include <stdlib.h>

#include "solution.h"
#include "stack.h"
#include "utils.h"

#define DEBUG_STACKS_BEFORE 0
#define DEBUG_STACKS_AFTER 0
#define DEBUG_INSTRUCTIONS 0

#define TAB "    "

void get_part_one_result(FILE* fp) {
    Input* input = get_input(fp);

    #if DEBUG_STACKS_BEFORE
    print_stacks(input);
    #endif 

    #if DEBUG_INSTRUCTIONS
    print_instructions(input);
    #endif

    apply_instructions(input);

    #if DEBUG_STACKS_AFTER
    print_stacks(input);
    #endif 

    printf("%sPart one: ", TAB);
    print_top_crates(input);

    free_input(input);
}

void get_part_two_result(FILE* fp) {
    Input* input = get_input(fp);

    #if DEBUG_STACKS_BEFORE
    print_stacks(input);
    #endif 

    apply_instructions_at_once(input);

    #if DEBUG_STACKS_AFTER
    print_stacks(input);
    #endif

    printf("%sPart two: ", TAB);
    print_top_crates(input);

    free_input(input);
}

int main(int argc, char** argv) {
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("The specified file does not exist: %s", filename);
        return 1;
    }

    get_part_one_result(fp);
    get_part_two_result(fp);

    fclose(fp);

    return 0;
}
