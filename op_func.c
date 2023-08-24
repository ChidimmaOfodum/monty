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

	if (data == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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

/**
 * pall - pushes an element to the stack
 * @stack: topmost stack element
 * @line_number: file line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		fflush(stdout);
		tmp = tmp->next;
	}

}

/**
 * pint - pushes an element to the stack
 * @stack: topmost stack element
 * @line_number: file line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);

}
