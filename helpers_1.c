#include "main.h"
/**
 * empty_line - check if the line is empty line
 * @str: pointer to the line
 * Return: 0 if empty
 */

int empty_line(char *str)
{
    int i, j;
    char *delim = " \n\t\a\b";
    /* Loop through each character in the 'line' string */
    for (i = 0; str[i]; i++)
    {
        /* For each character in 'line', check against each delimiter */
        for (j = 0; delim[j]; j++)
        {
            if (str[i] == delim[j])
                break;
            /* If the inner loop reached the end of 'delims' (no match found) */
            /* it means the current character in 'line' is not a delimiter*/
            if (delim[j] == '\0')
                return(0);
        }
    }
    /* If the outer loop completes without finding any non-delimiter characters*/
    /* Return 1, indicating that the line is empty*/
    return (1);
    }