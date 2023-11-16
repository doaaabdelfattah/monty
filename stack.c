#include "monty.h"
/**
 * start_stack - initialize stack
 * @stack: pointer to node
 * Return: 0 if success
*/
int start_stack(stack_t **stack)
{
    stack_t *new_node;
    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
        return(err_malloc());

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->n = 0;
    *stack = new_node;
    printf("stack created");
    return(0);
}

void free_stack(stack_t **stack)
{
    stack_t *tmp;
    tmp = *stack;
    while(*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}