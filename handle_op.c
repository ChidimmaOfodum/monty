#include "monty.h"

/**
 * execute_Stack_op - executes a particular function if valid
 * according to the LIFO format
 * @op_name: operation name
 * @stack: pointer to topmost stack element
 * @line_number: file line number
 * Return: void
 */
void execute_Stack_op(char *op_name, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t operation[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divid},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	while (operation[i].opcode)
	{
		if (strcmp(op_name, operation[i].opcode) == 0)
		{
			operation[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (operation[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_name);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_Queue_op - executes a particular function if valid
 * and performs operation based on the FIFO rule
 * @op_name: operation name
 * @stack: pointer to topmost stack element
 * @line_number: file line number
 * Return: nothing
 */
void execute_Queue_op(char *op_name, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t operation[] = {
		{"push", qPush}, /* queue push() function */
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divid},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	while (operation[i].opcode)
	{
		if (strcmp(op_name, operation[i].opcode) == 0)
		{
			operation[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (operation[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_name);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * qPush - push an element to stack using queue format (FIFO)
 * @stack: pointer to the topmost element
 * @line_number: line containing opcode
 * Return: nothing
 */
void qPush(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *top, *new;
	int n, ln = line_number;

	top = bottom = *stack;
	if (!stream.data || isInteger(stream.data) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(stream.data);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	if (!*stack)
		*stack = new;
	else
	{
		while (bottom->next != NULL)
			bottom = bottom->next;
		bottom->next = new;
		*stack = top;
	}
}
