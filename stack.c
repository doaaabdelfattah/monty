#include "monty.h"
/**
 * start_stack - initialize stack
 * @stack: pointer to node
 * Return: 0 if success
 */
int start_stack(stack_t **stack)
{
	*stack = NULL;
	return (0);
}
/**
 * free_stack - free stack
 * @stack: pointer to node
 */
void free_stack(stack_t **stack)
{
	stack_t *curr, *next;

	curr = *stack;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}
