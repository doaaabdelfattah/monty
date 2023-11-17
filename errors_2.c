#include "monty.h"
/**
 * err_int - If value not an integer or if there is no argument given to push
 * @line: line number
 * Return: Exit Failure
 */

int err_int(int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	return(EXIT_FAILURE);
}
