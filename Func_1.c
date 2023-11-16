#include "monty.h"

/**
 * my_push - pushes an element to the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
 */

void my_push(stack_t **stack,  unsigned int line_number)
{
	stack_t *new_node;
	int i;

	i = 0;
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		err_malloc();
		return;
	}
	/* Check if the number is valid or the array itself */
	if (opcode == NULL ||opcode[1] == NULL)
	{
		err_int(line_number);
		free(new_node);
		return;
	}
	while (opcode[1][i])
	{
		if (i == 0 && opcode[1][i] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(opcode[1][i]))
		{
			err_int(line_number);
			free(new_node);
			return;
		}
		i++;
	}
	new_node->n = atoi(opcode[1]);
    /* Connect both sides */
	new_node->next = *stack;
	new_node->prev = NULL;
	/* handle the case when the stack is not empty*/
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * my_pall - print all element of the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
 */

void my_pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack == NULL)
		return;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * my_pint - print top element of the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
 */

void my_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack != NULL)
	    printf("%d\n", (*stack)->n);
    else
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    }
}