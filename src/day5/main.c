#include <stdio.h>
#include <stdlib.h>

#include "solution.h"
#include "stack.h"
#include "utils.h"

#define DEBUG 0

#define TAB "    "

void get_part_one_result(FILE* fp) {
    Input* input = get_input(fp);

    #if DEBUG
    printf("Stacks:\n");
    for (int i = 0; i < input->crate_stack_count; i++) {
        print_stack(i, input->crate_stacks[i]);
    }

    printf("Instructions:\n");
    for (int i = 0; i < input->instruction_count; i++) {
        print_instruction(i, input->instructions[i]);
    }
    #endif

    apply_instructions(input);

    printf("%sPart one: ", TAB);
    for (int i = 0; i < input->crate_stack_count; i++) {
        printf("%c ", peek(input->crate_stacks[i]));
    }
    printf("\n");

    free_input(input);
}

void get_part_two_result(FILE* fp) {
    printf("%sPart one: ", TAB);
    printf("Not yet implemented.");
    printf("\n");
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
