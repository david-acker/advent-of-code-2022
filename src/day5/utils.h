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

void print_stack(int stack_number, Stack* stack);
void print_instruction(int instruction_number, Instruction* instruction);

#endif