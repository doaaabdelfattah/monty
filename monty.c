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
	int line_num;
	stack_t *stack;
	char *input;
	void (*operation)(stack_t **, unsigned int);
	input = NULL;
	bufsize = 0;
	line_num = 0;
	stack = NULL;

	/* Initialize stack */
	start_stack(&stack);
    /* iterate over lines */
	while (getline(&input, &bufsize, fileptr) != -1)
	{
		/* Line numbers always start at 1 */
		line_num++;
		/* Get the opcode array of strings */
		opcode = pars_input(input);
		if (opcode == NULL)
		{
			if (empty_line(input))
				continue;
			free_stack(&stack);
			free(input);
			return(err_malloc());
		}
        /* Get the function required*/
		operation = handle_opcode(opcode[0]);
		if (operation == NULL)
		{
			free_stack(&stack);
			free_grid(opcode);
			free(input);
			return (err_invalid_instr(line_num, opcode[0]));
		}
		operation(&stack, line_num);
		free_grid(opcode);
	};
	free_stack(&stack);
	free(input);
	return (0);
}

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
		  /*{"swap", my_swap},
		  {"add", my_add},
		  {"nop", my_nop},*/
		{NULL, NULL}};
	int i;

	i = 0;
	while (fun_list[i].opcode)
	{
		if (strcmp(fun_list[i].opcode, str) == 0)
			return (fun_list[i].f);
		i++;
	}
	return(NULL);
}
