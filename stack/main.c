#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack stack = create_new_stack();
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);
    
    printf("Popped: %d\n", pop(&stack));
    display(&stack);
    
    return 0;
}