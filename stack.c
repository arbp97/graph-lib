#include "stack.h"

Stack *create_stack()
{
    Stack *new = (Stack *)malloc(sizeof(Stack));

    new->top = NULL;

    return new;
}

void push(Stack **stack, Node *node)
{
    if (!*stack || !node)
        printf("\nERROR: Invalid or null arguments");

    node->next = (*stack)->top;
    (*stack)->top = node;
}

Node *pop(Stack **stack)
{
    if (!*stack)
        printf("\nERROR: Invalid or null arguments");

    Node *out = (*stack)->top;

    (*stack)->top = (*stack)->top->next;

    return out;
}

bool is_stack_empty(Stack *stack)
{
    if (stack)
    {
        if (stack->top)
            return false;
    }
    else
    {
        printf("\nERROR: Queue is null");
    }

    return true;
}

void delete_stack(Stack **stack)
{
    if (!*stack)
    {
        printf("/nERROR: stack is null");
    }
    else
    {
        Node *cursor = (*stack)->top;
        Node *aux = NULL;

        while (cursor)
        {
            aux = cursor->next;
            free(cursor);
            cursor = NULL;

            cursor = aux;
        }

        free(*stack);
        *stack = NULL;
    }
}