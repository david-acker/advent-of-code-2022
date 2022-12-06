
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