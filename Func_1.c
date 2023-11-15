#include "main.h"
/**
 * _push: pushes an element to the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
*/

void my_push (stack_t **stack, unsigned int line_number)
{
    stack_t *new_node, *tmp;
    int i;
    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
        return (err_malloc());

    new_node->n = value;
    new_node->prev = *stack;
    new_node->next = NULL;
    /* handle the case when the stack is not empty */
    if (*stack != NULL)
    {
        (*stack)->next = new_node;
    }
    *stack = new_node;
}
