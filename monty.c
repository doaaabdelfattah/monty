#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>
/**
 * monty - main function to execute Monty Bytecode
 * @fileptr: File descriptor for an open script
 * Return: 0 if success
 */
int monty(FILE *fileptr)
{
	size_t bufsize;
	stack_t *stack;
	int line_num;
	char *input;
	void (*operation)(stack_t **, unsigned int);

	input = NULL;
	bufsize = 0;
	line_num = 0;
	stack = NULL;
	start_stack(&stack);/* Initialize stack */

	while (getline(&input, &bufsize, fileptr) != -1) /* iterate over lines */
	{
		line_num++; /* Line numbers always start at 1 */
		if (empty_line(input)) /* if there's empty lines  */
			continue;
		opcode = pars_input(input); /* Get the opcode array of strings */
		if (opcode == NULL)
		{
			free_stack(&stack);
			free(input);
			exit(err_malloc());
		}
		else if (opcode[0][0] == '#' && (free_grid(opcode), 1)) /* Handle comments */
			continue;
		operation = handle_opcode(opcode[0]); /* Get the function required*/
		if (operation == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode[0]);
			triple_free(&stack, opcode, input);
			return (EXIT_FAILURE);
		}
		operation(&stack, line_num);
		free_grid(opcode);
	};
	free_stack(&stack);
	free(input);
	return (0);
}

/**
 *handle_opcode - function to handle if the command is built ib
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
		{"sub", my_sub},
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
