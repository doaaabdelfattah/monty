
#include "main.h"
/**
*handle_builtin - function to handle if the command is built ib
*@str: string to be checked
*Return: the function
*/
void (*handle_opcode(char *str))(stack_t**, unsigned int)
{
	instruction_t fun_list[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{NULL, NULL}};
	int i;

	i = 0;
	while (fun_list[i].opcode)
	{
		if (strcmp(fun_list[i].opcode, str) == 0)
			return (fun_list[i].f);
		i++;
	}
	return (NULL);
}

stack_t *create_node(int n)
{
	stack_t *new_node;
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (err_malloc());

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}
