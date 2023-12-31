#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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

/**
 * struct glob - stream and its data
 * @data: data gotten from stream
 * @o: stream
 *
 * Descripption: stream and its data gotten from the stream
 */
typedef struct glob
{
	char *data;
	FILE *o;
} glob;

extern glob stream;

/* Stack Format: LIFO (Last In, First Out!)*/
void execute_Stack_op(char *op_name, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

/* Queue Format: FIFO (First In, First Out!)*/
void execute_Queue_op(char *op_name, stack_t **stack, unsigned int line_number);
void qPush(stack_t **stack, unsigned int line_number);

/* Other opcode functions */
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
/* changed the name, because there's a standard div function */
void divid(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* call other execute function to match a format */
int execute_op_format(char *op_name, stack_t **stack, unsigned int line_number);

/* Other helpful functions */
void freeStack(stack_t *stack);
int isInteger(char *data);

#endif /** MONTY_H **/
