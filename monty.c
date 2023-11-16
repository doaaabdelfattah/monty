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
    stack_t **stack;
    char *input, *opcode;
    void (*operation)(stack_t **, unsigned int);
    
    bufsize = 0;
    line_num = 0;
    stack = NULL;
    /* Initialize stack */
    if (start_stack(stack) == EXIT_FAILURE)
        return (err_malloc());

    while (getline(&input, &bufsize, fileptr) != -1)
    {
        /* Line numbers always start at 1 */
        line_num++;
        /* Get the first opcode */
        opcode = strtok(input, " \n\t\a\b");

        if (opcode == NULL)
        {
            if (empty_line(input))
                continue;
            free_stack(stack);
            return(err_malloc());
        }
        /* value = strtok(NULL, " \n\t\a\b");*/

        free(input);

        operation = handle_opcode(opcode);
        if (operation == NULL)
            return (err_invalid_instr(line_num, opcode));

        operation(stack, line_num);
    }
    free(input);
    return (0);
}
