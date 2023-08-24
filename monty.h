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

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void freeStack(stack_t *stack);
void nop(stack_t **stack, unsigned int line_number);
void execute_op(char *op_name, stack_t **stack, unsigned int line_number);
void error_handling(stack_t *stack, char *op_name, char *op_data,
		unsigned int line_number, FILE *o);
void error_handling2(stack_t *stack, char *op_name,
		unsigned int line_number, FILE *o);
#endif /** MONTY_H **/
