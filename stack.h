#ifndef _STACK_H_
#define _STACK_H_

#include "queue.h"

/*
Uses structures and functions 
from Queue.h
*/

typedef struct Stack
{
    Node* top;
} Stack;

Stack* create_stack();

// push a node into the stack
void push(Stack** stack, Node* node);

// pop the last node added (top)
Node* pop(Stack** stack);

bool is_stack_empty(Stack* stack);

void delete_stack(Stack** stack);

#endif // !_STACK_H_
