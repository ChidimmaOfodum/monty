#include "monty.h"

/**
 * error_handling - handles edge cases for each opcode
 * @stack: the topmost element
 * @op_name: opcode name
 * @op_data: data to be pushed
 * @line_number: line number containing error
 * @o: stream
 * Return: nothing
 */
void error_handling(stack_t *stack, char *op_name, char *op_data,
		unsigned int line_number, FILE *o)
{
	int n;

	if (strcmp("push", op_name) == 0)
	{
		if (op_data == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(o);
			freeStack(stack);
			exit(EXIT_FAILURE);
		}
		n = atoi(data);
		if (strcmp(op_data, "0") != 0 && n == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(o);
			freeStack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp("pint", op_name) == 0)
	{
		if (stack == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty", line_number);
			fclose(o);
			freeStack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp("pop", op_name) == 0)
	{
		if (stack == NULL)
		{
			n = line_number;
			fprintf(stderr, "L%d: can't pop an empty stack\n", n);
			fclose(o);
			freeStack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
		error_handling2(stack, op_name, line_number, o);
}

/**
 * error_handling2 - handles edge cases for each opcode
 * @stack: the topmost element
 * @op_name: opcode name
 * @line_number: line number containing error
 * @o: stream
 * Return: nothing
 */
void error_handling2(stack_t *stack, char *op_name,
		unsigned int line_number, FILE *o)
{
	int n;

	if (strcmp("swap", op_name) == 0)
	{
		if (stack->next == NULL || !stack) /* Not up to two element */
		{
			n = line_number;
			fprintf(stderr, "L%d: can't swap, stack too short\n", n);
			fclose(o);
			freeStack(stack);
			exit(EXIT_FAILURE);
		}
	}

	else if (strcmp("add", op_name) == 0)
	{
		if (stack->next == NULL || !stack)
		{
			n = line_number;
			fprintf(stderr, "L%d: can't add, stack too short\n", n);
			fclose(o);
			freeStack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		freeStack(stack);
		fclose(o);
	}
}
