#ifndef STACK
#define STACK

typedef struct Stack {
    int capacity;
    int size;
    char* items;
} Stack;

Stack* new_stack(int capacity);
void free_stack(Stack* stack);
int is_empty(Stack* stack);

char peek(Stack* stack);
char pop(Stack* stack);
void push(Stack* stack, char value);
void push_bottom(Stack* stack, char value);

#endif