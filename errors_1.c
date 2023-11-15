#include "monty.h"
/**
 * err_arg - If user does not give any file
 * Return: Exit Failure
 */

int err_arg(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}


/**
 * err_invalid_instr - If the file contains an invalid instruction
 * @line: Line number
 * @str: pointer to opcode
 *  Return: Exit Failure
*/
int err_invalid_instr(int line, char *str)
{
    fprintf(stderr, "L%d: unknown instruction %s", line, str);
    exit(EXIT_FAILURE);
}

/**
 * err_invalid_instr - If the file contains an invalid instruction
 * @line: Line number
 * @str: pointer to opcode
 *  Return: Exit Failure
*/
int err_open_file(char *str)
{
    fprintf(stderr, "Error: Can't open %s\n", str);
    exit(EXIT_FAILURE);
}

/**
 * err_invalid_instr - If the file contains an invalid instruction
 * @line: Line number
 * @str: pointer to opcode
 *  Return: Exit Failure
*/
int err_malloc(void)
{
    fprintf(stderr, "Error: malloc failed");
    exit(EXIT_FAILURE);
}

