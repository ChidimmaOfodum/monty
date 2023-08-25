#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: topmost stack element
 * @line_number: file line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int n, status = 0;

	if (stream.data == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		status = 1;
	}

	n = atoi(stream.data);
	if (strcmp(stream.data, "0") != 0 && n == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		status = 1;
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		status = 1;
	}
	if (status == 1)
	{
		fclose(stream.o);
		freeStack(*stack);
		if (new_node)
			free(new_node);
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
		n = line_number;
		fprintf(stderr, "L%d: can't pint, stack empty", n);
		fclose(stream.o);
		freeStack(*stack);
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
	int n;

	if (*stack == NULL)
	{
		n = line_number;
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		fclose(stream.o);
		freeStack(*stack);
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
	int tmp, n, status = 0;

	if (*stack == NULL)
		status = -1;
	else if ((*stack)->next == NULL)
		status = -1;
	if (status == -1)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	sec_top = top->next;

	/* Swapping takes place */
	tmp = top->n;
	top->n = sec_top->n;
	sec_top->n = tmp;
}
