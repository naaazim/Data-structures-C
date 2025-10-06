#ifndef __STACK_H__
#define __STACK_H__

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;    

typedef struct Stack {
    StackNode* top;
} Stack;    

Stack create_new_stack(void);
int is_empty_stack(const Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
void display(const Stack* stack);

#endif 