#include "monty.h"
char *data;

/**
 * push - pushes an element to the stack
 * @stack: topmost stack element
 * @line_number: file line number
 * Return: void
 */


void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int n;

	n = atoi(data);
	if (strcmp(data, "0") != 0 && n == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;

	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;

}

