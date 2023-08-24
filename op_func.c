#include "monty.h"

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
 * pall - prints all the elements in stack
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

/**
 * pop - deletes the topmost element of the stack
 * @stack: topmost stack element
 * @line_number: line number of the opcode(instruction)
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(top);
}

/**
 * swap - swaps the top two element of the stack
 * @stack: topmost stack element
 * @line_number: line number of the opcode(instruction)
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *sec_top;
	int tmp;

	if ((*stack)->next == NULL || !*stack) /* Not up to two element */
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	sec_top = top->next;

	/* Swapping takes place */
	tmp = top->n;
	top->n = sec_top->n;
	sec_top->n = tmp;
}

/**
 * add - adds the data of the top two stack element
 * @stack: topmost stack element
 * @line_number: line number of the opcode(instruction)
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *sec_top;

	if ((*stack)->next == NULL || !*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sec_top = top->next;
	/* Let the second-top data be the top's data added to its own data */
	sec_top->n = sec_top->n + top->n;
	*stack = sec_top;
	free(top);
}
