#include "monty.h"


stack_t *create_node(int n)
{
	stack_t *new_node;
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
		{
			err_malloc();
			return (NULL);
		}

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}
