#include "monty.h"
/**
 *pars_input - split input aand save it in array
 *@input: pointer to string (input)
 * Return: pointer to array pointer
 */

char **pars_input(char *input)
{
int i, j;
char *token;
int counter;
char **opcode;

i = 0;
if (input == NULL)
	return (NULL);
counter = count_tokens(input);
if (counter < 0)
	return (NULL);
opcode = malloc(sizeof(char *) * (counter + 1));
if (opcode == NULL)
{
	free(input);
	err_malloc();
	return(NULL);
}
token = strtok(input, " \n\t\a\b");
if (token == NULL)
{
	free(input);
	free(opcode);
	return (NULL);
}
while (token)
{
	opcode[i] = malloc(sizeof(char) * (strlen(token) + 1));
	if (opcode[i] == NULL)
	{
		for (j = 0; j < i; j++)
			free(opcode[j]);
		free(opcode);
		free(input);
		err_malloc();
		return(NULL);	}
	strcpy(opcode[i], token);
	i++;
	token = strtok(NULL, " \n\t");
}
opcode[counter] = NULL;
return (opcode); }

/**
*count_tokens - count number of tokens
*@input: input
*Return: count of tokens
*/

int count_tokens(char *input)
{
	int counter;
	char *input_copy;
	char *token;

	counter = 0;
	input_copy = strdup(input);
	if (input_copy == NULL)
		return (-1);
	/* Parsing the copy to know words count*/
	token = strtok(input_copy, " \n\t");
	/* Calculate input words (tokens) */
	while (token)
	{
		counter++;
		token = strtok(NULL, " \n\t");
	}
	free(input_copy);
	input_copy = NULL;
	return (counter);
}