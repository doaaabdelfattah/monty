#include "main.h"
/**
 * monty - main function to execute Monty Bytecode
 * @fileptr: File descriptor for an open script
 * Return: 0 if success
*/
int monty(FILE *fileptr)
{
    int exit_status, bufsize, line_num;
    char *input, *opcode;
    void (*operation)(stack_t**, unsigned int);
    unsigned int line_num = 0;
    exit_status = 0;

    while(getline(&input, &bufsize, fileptr) == -1)
    {
        /* Line numbers always start at 1 */
        line_num++;
        /* Get the first opcode */
        opcode = strtok(input, " \n\t\a\b");

        if (opcode == NULL)
        {
            if(empty_line(input))
                continue;
            return(err_malloc());
        }
        value = strtok(NULL, " \n\t\a\b");

        free(input);

        operation = handle_opcode(opcode);
        if (operation == NULL)
            return(err_invalid_instr(line_num, opcode));

        return (operation(opcode, line_num));
    }

}

