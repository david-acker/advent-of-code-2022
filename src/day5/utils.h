#ifndef UTILS
#define UTILS

#include <stdio.h>

#include "stack.h"

typedef struct Instruction {
    int crate_count;
    int start;
    int end;
} Instruction;

typedef struct Input {
    Stack** crate_stacks;
    int crate_stack_count;

    Instruction** instructions;
    int instruction_count;
} Input;

Input* get_input(FILE* fp);
void free_input(Input* input);

void print_stacks(Input* input);
void print_instructions(Input* input);

void print_top_crates(Input* input);

#endif