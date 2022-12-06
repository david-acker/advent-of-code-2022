#include <stdlib.h>

#include "stack.h"
#include "utils.h"

void apply_instructions(Input* input) {
    for (int i = 0; i < input->instruction_count; i++) {
        Instruction* instruction = input->instructions[i];

        Stack* source = input->crate_stacks[instruction->start];
        Stack* destination = input->crate_stacks[instruction->end];

        int remaining_crates = instruction->crate_count;
        while (remaining_crates > 0) {
            push(destination, pop(source));
            remaining_crates--;
        }
    }
}

void apply_instructions_at_once(Input* input) {
    for (int i = 0; i < input->instruction_count; i++) {
        Instruction* instruction = input->instructions[i];

        Stack* source = input->crate_stacks[instruction->start];
        Stack* destination = input->crate_stacks[instruction->end];

        int crate_count = instruction->crate_count;
        char* crates_to_move = (char*)calloc(crate_count, sizeof(char));

        for (int j = 0; j < crate_count; j++) {
            char c = pop(source);
            crates_to_move[j] = c;
        }

        for (int j = 0; j < crate_count; j++) {
            push(destination, crates_to_move[crate_count - j - 1]);
        }

        free(crates_to_move);
    }
}