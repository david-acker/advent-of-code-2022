#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int capacity;
    int size;
    char* items;
} Stack;

Stack* new_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->capacity = capacity;
    stack->size = 0;
    stack->items = (char*)malloc(0);

    return stack;
}

void free_stack(Stack* stack) {
    free(stack->items);
    free(stack);
}

int is_empty(Stack* stack) {
    return stack->items == 0;
}

char peek(Stack* stack) {
    if (is_empty(stack)) {
        return '\0';
    }

    return stack->items[stack->size - 1];
}

void increase_capacity(Stack* stack) {
    int new_capacity = stack->capacity * 2;

    stack->capacity = new_capacity;
    stack->items = (char*)realloc(stack->items, new_capacity);
}

void check_capacity(Stack* stack) {
    if (stack->size + 1 > stack->capacity) {
        increase_capacity(stack);
    }
}

void push(Stack* stack, char value) {
    check_capacity(stack);

    stack->size++;
    stack->items[stack->size - 1] = value;
}

void push_bottom(Stack* stack, char value) {
    check_capacity(stack);

    memcpy(stack->items + 1, stack->items, stack->size);
    stack->items[0] = value;
    stack->size++;
}

char pop(Stack* stack) {
    if (is_empty(stack)) {
        return '\0';
    }

    stack->size--;
    return stack->items[stack->size];
}