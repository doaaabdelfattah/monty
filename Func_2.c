#include "monty.h"
/**
 * my_pop - removes the top element of the stack.
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

/**
 * my_swap - swaps the top two elements of the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
 */

void my_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *last, *pre;
    int data;
    /* if list is empty or has only one node:*/
    if (dlistint_len(*stack) < 2)
    {        
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* Set up pointers to the last two nodes */
    last = *stack;
    pre = (*stack)->next;
    /* Swap the values of the last two nodes */
    data = last->n;
    last->n = pre->n;
    pre->n = data;
}


