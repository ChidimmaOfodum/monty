#include "monty.h"

/**
 * mod - computes the remainder of the second-top's element data by
 * the top's data
 * @stack: pointer to the topmost element
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *sec_top;
	int n = line_number, status = 0;

	if (*stack == NULL)
		status = -1;
	else if ((*stack)->next == NULL)
		status = -1;

	if (status == -1)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", n);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	sec_top = top->next;
	sec_top->n = sec_top->n % top->n;
	*stack = sec_top;
	free(top);
}

/**
 * pchar - prints the char at the top of the stack, followed by a newline
 * @stack: pointer to the topmost element of the stack
 * @line_number: line containing "pchar" opcode
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int n = line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	if (top->n < 0 || top->n > 127) /* Ascii chars range */
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	putchar(top->n);
	putchar('\n');
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the topmost element of the stack
 * @line_number: line containing opcode
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *elem = *stack;

	(void)line_number; /* Unused! */
	while (elem != NULL) /* while traversing the stack */
	{
		/* if n is either 0 or out of range */
		if (elem->n <= 0 || elem->n > 127)
			break; /* stop printing */
		putchar(elem->n);
		elem = elem->next;
	}
	putchar('\n');
	*stack = top; /* updating stack position back to the top */
}

/**
 * rotl - rotates stack elements to the top
 * @stack: pointer to the topmost element
 * @line_number: line containing opcode
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top; /* top becomes bottom */
	stack_t *sec_top; /*second becomes top */
	stack_t *bottom;

	(void)line_number; /* Unused! */
	top = bottom = *stack;
	sec_top = top->next;

	if (*stack == NULL)
		;
	else
	{
	/* traversing until last element is reached */
		while (bottom->next != NULL)
		{
			bottom = bottom->next;
		}

	/* Connecting the top element to the bottom element */
		bottom->next = top;
		top->prev = bottom;

	/* Cutting off the link between second-top and top to avoid circularity */
		sec_top->prev = NULL;
		top->next = NULL;

	/* Updating stack to be the new top of the list*/
		*stack = sec_top;
	}
}

/**
 * rotr - rotates stack elements to the bottom
 * @stack: pointer to the topmost element of the stack
 * @line_number: line containing opcoode
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *sec_bottom;
	stack_t *bottom;

	(void)line_number;
	top = bottom = *stack;

	if (!*stack)
		;
	else
	{
		while (bottom->next != NULL)
		{
			bottom = bottom->next;
		}
		sec_bottom = bottom->prev;

		top->prev = bottom;
		bottom->next = top;
		sec_bottom->next = NULL;
	}
}
