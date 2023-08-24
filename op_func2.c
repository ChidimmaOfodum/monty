#include "monty.h"

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
	int n;

	if ((*stack)->next == NULL || !*stack)
	{
		n = line_number;
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	sec_top = top->next;
	/* Let the second-top data be the top's data added to its own data */
	sec_top->n = sec_top->n + top->n;
	*stack = sec_top;
	free(top);
}

/**
 * nop - does nothing
 * @stack: topmost element of the stack
 * @line_number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}
