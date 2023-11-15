#include "monty.h"
/**
 * _push: pushes an element to the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
*/

void my_push (stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        err_malloc();
        return;
    }
    if (value == NULL)
    {
        err_int(line_number);
        return;
    }

    new_node->n = atoi(value);
    new_node->prev = *stack;
    new_node->next = NULL;
    /* handle the case when the stack is not empty */
    if (*stack != NULL)
    {
        (*stack)->next = new_node;
    }
    *stack = new_node;
}
