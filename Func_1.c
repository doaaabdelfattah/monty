#include "monty.h"
/**
 * _push: pushes an element to the stack.
 * @stack: pointer to the top element of the stack
 * @line_number: currrent working line of Monty bytecode/
*/

void my_push (stack_t **stack,  unsigned int line_number)
{
    stack_t *new_node;
    int i;
    i = 0;
    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        err_malloc();
        return;
    }
    /* Check if the number is valid*/
     if (opcode[1] == NULL)
    {
        err_int(line_number);
        free(new_node);
        return;
    }
    while(opcode[1][i])
    {
        if (opcode[1][0] == '-')
        {
            i++;
            continue;
        }
        if (opcode[1][i] < '0' || opcode[1][i] > '9')
        {
        err_int(line_number);
        free(new_node);
        return;
        }
        i++;
    }
    
    new_node->n = atoi(opcode[1]);
    new_node->prev = *stack;
    new_node->next = NULL;
    /* handle the case when the stack is not empty*/
    if (*stack != NULL)
    {
        (*stack)->next = new_node;
    }
    *stack = new_node; 
    /* printf(" Line num is %d and value is %s\n",line_number, opcode[1]);*/
}

void my_pall (stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    stack_t *tmp;
    tmp = *stack;
    if(*stack == NULL)
    return;

    while(tmp != 0)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->prev;
    }
}