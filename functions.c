#include "main.h"
/**
 * _push: pushes an element to the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
*/

void _push (stack_t **stack, unsigned int line_number)
{
    stack_t *new_node, *tmp;
    int i;
    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        return;
        /* Print error malloc */
    }
    

}


int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}