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
	int n, status;

	if (*stack == NULL)
		status = -1;
	else if ((*stack)->next == NULL)
		status = -1;
	if (status == -1)
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
 * @line_number: line having the opcode
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}

/**
 * sub - subtract the topmost element data from the second-top data
 * @stack: pointer to topmost element of the stack
 * @line_number: line containing opcode
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *sec_top;
	int n, status = 0;

	if (*stack == NULL)
		status = -1;
	else if ((*stack)->next == NULL)
		status = -1;

	if (status == -1)
	{
		n = line_number;
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	sec_top = top->next;
	sec_top->n = sec_top->n - top->n;
	*stack = sec_top;
	free(top);
}

/**
 * divid - divides the second-top data by the top data in the stack
 * @stack: pointer to the topmost element of the stack
 * @line_number: line containing opcode
 * Return: nothing
 */
void divid(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", n);
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
	sec_top->n = sec_top->n / top->n;
	*stack = sec_top;
	free(top);
}

/**
 * mul - multiply the topmost element data by the second-top data
 * @stack: pointer to topmost element of the stack
 * @line_number: line containing opcode
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		fclose(stream.o);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	sec_top = top->next;
	sec_top->n = sec_top->n * top->n;
	*stack = sec_top;
	free(top);
}
