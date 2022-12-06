#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef enum Section { 
    Crates, 
    Blank, 
    Instructions
} Section;

void parse_crate_row(char* buffer, Stack*** crate_stacks, int* crate_stack_count, Section* section, int* is_initialized) {
    int stack_index = 0;

    for (int i = 1; i < strlen(buffer); i += 4) {
        char value = buffer[i];

        if (value >= '1' && value <= '9') {
            // Move on to next section (blank)
            *section = Blank;
            break;
        }

        if (*is_initialized == 0) {
            *crate_stacks = (Stack**)realloc(*crate_stacks, sizeof(Stack*) * (*crate_stack_count + 1));
            (*crate_stacks)[stack_index] = new_stack(1);
        }

        if (value >= 'A' && value <= 'Z') {
            Stack* crate_stack = (*crate_stacks)[stack_index];
            push_bottom(crate_stack, value);
        }

        stack_index++;
        if (*is_initialized == 0) {
            (*crate_stack_count)++;
        }
    }

    if (*is_initialized == 0) {
        *is_initialized = 1;
    }
}

void parse_instruction_row(char* buffer, Instruction*** instructions, int* instruction_count) {
    
    char delimiter[] = " ";
    char *ptr = strtok(buffer, delimiter);

    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));

    int column = 1;
    while (ptr != NULL) {
        switch (column) {
            case 2:
                instruction->crate_count = atoi(ptr);
                break;
            case 4:
                instruction->start = atoi(ptr) - 1;
                break;
            case 6:
                instruction->end = atoi(ptr) - 1;
                break;
            default:
                break;
        }

        ptr = strtok(NULL, delimiter);
        column++;
    }

    (*instruction_count)++;
    *instructions = (Instruction**)realloc(*instructions, sizeof(Instruction*) * (*instruction_count));
    (*instructions)[(*instruction_count) - 1] = instruction;
}

Input* get_input(FILE* fp) {
    fseek(fp, 0, SEEK_SET);

    Stack** crate_stacks = (Stack**)malloc(0);
    int crate_stack_count = 0;

    Instruction** instructions = (Instruction**)malloc(0);
    int instruction_count = 0;

    int is_initialized = 0;
    Section section = Crates;

    int buffer_length = 100;
    char* buffer = calloc(buffer_length, sizeof(char));

    while (fgets(buffer, (buffer_length * sizeof(char)), fp) != NULL) {

        switch (section) {
            case Crates:
                parse_crate_row(
                    buffer,
                    &crate_stacks, 
                    &crate_stack_count,
                    &section,
                    &is_initialized);
                break;
            case Blank:
                section = Instructions;
                break;
            case Instructions:
                parse_instruction_row(
                    buffer,
                    &instructions, 
                    &instruction_count);
                break;
            default:
                printf("Invalid section\n");
                exit(1);
        }

        memset(buffer, '\0', sizeof(char));
    }

    Input* input = (Input*)malloc(sizeof(Input));
    input->crate_stacks = crate_stacks;
    input->crate_stack_count = crate_stack_count;
    input->instructions = instructions;
    input->instruction_count = instruction_count;

    return input;
}

void free_input(Input* input) {
    for (int i = 0; i < input->crate_stack_count; i++) {
        free_stack(input->crate_stacks[i]);
    }
    for (int i = 0; i < input->instruction_count; i++) {
        free(input->instructions[i]);
    }
    free(input->crate_stacks);
    free(input);
}

void print_stack(int stack_number, Stack* stack) {
    printf("%d | ", stack_number);
    for (int i = 0; i < stack->size; i++) {
        printf("%c ", stack->items[i]);
    }
    printf("\n");
}

void print_instruction(int instruction_number, Instruction* instruction) {
    printf("%d | %d %d %d\n", instruction_number, instruction->crate_count, instruction->start, instruction->end);
}