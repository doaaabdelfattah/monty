#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <fcntl.h>

extern char **opcode;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* Errors Functions */
int err_arg(void);
int err_invalid_instr(int line, char *str);
int err_open_file(char *str);
int err_malloc(void);
int err_int(int line);



/* Primary functions */
int monty(FILE *fileptr);
void (*handle_opcode(char *str))(stack_t**, unsigned int);
char **pars_input(char *input);
int count_tokens(char *input);


/* Stack Function */
int start_stack(stack_t **stack);
void free_stack(stack_t **stack);


/* operation Functions */
void my_push (stack_t **stack, unsigned int line_number);
void my_pall (stack_t **stack, unsigned int line_number);
void my_pint (stack_t **stack, unsigned int line_number);
/*void my_pop (stack_t **stack, unsigned int line_number);
  void my_swap (stack_t **stack, unsigned int line_number);
  void my_add (stack_t **stack, unsigned int line_number);
  void my_nop (stack_t **stack, unsigned int line_number);*/
  
int empty_line(char *str);
void free_grid(char **grid);

#endif
