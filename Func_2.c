#include "monty.h"
/**
 * my_pint - print top element of the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
 */

void my_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr;
    ptr = *stack;
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* if only one node */
   if ((*stack)->next == NULL)
    {
        free(*stack);
        *stack = NULL;
    }
    else
    {
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(ptr);
    }
    
}


