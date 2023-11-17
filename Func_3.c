#include "monty.h"

/**
 * my_mul - mutiply the top two elements of the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
 */

void my_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *pre;
	/* if list is empty or has only one node:*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Set up pointers to the last two nodes */
	last = *stack;
	pre = (*stack)->next;
	/* sub the values to the second top */
	pre->n *= last->n;
	/* the top element is removed */
	*stack = pre;
	pre->prev = NULL;
	free(last);
	if (*stack == NULL)
		/* Stack is empty, set the stack pointer to NULL */
		*stack = NULL;
}