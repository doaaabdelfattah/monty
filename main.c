#include "monty.h"
char **opcode = NULL;
/**
 * main - Entry point for monty program
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: 0 (EXIT_SUCCESS) if success, 1 on error
 */

int main(int argc, char **argv)
{
	int exit_status;
	FILE *fileptr;

	exit_status = 0;
	if (argc != 2)
		return (err_arg());

	fileptr = fopen(argv[1], "r");
	/* Check if the file was opened successfully */
	if (fileptr == NULL)
		return (err_open_file(argv[1]));
	exit_status = monty(fileptr);
	fclose(fileptr);
	return (exit_status);
}
