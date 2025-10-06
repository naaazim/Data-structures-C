#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack create_new_stack(void) {
    Stack stack;
    stack.top = NULL;
    return stack;
}

int is_empty_stack(const Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int value) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if (!new_node) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack *stack) {
    if (is_empty_stack(stack)) {
        fprintf(stderr, "La pile est vide, impossible de dépiler.\n");
        return -1; // Valeur indicative d'erreur
    }
    StackNode *temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

void display(const Stack *stack) {
    StackNode *current = stack->top;
    while (current != NULL) {
        printf("[%d]\n", current->data);
        current = current->next;
    }
}