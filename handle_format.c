#include "monty.h"

/**
 * execute_op_format - execute operation based on a format (LIFO / FIFO)
 * @op_name: operation name
 * @stack: the topmost element
 * @line_number: line containing operation name
 * Return: 1 if queue format, 0 if stack
 */
int execute_op_format(char *op_name, stack_t **stack, unsigned int line_number)
{
	static char format[6] = "stack"; /* default format to use */

	if (strcmp(op_name, "queue") == 0 || strcmp(op_name, "stack") == 0)
	{
		strcpy(format, op_name);
		return (1);
	}

	if (strcmp(format, "queue") == 0)
	{
		execute_Queue_op(op_name, stack, line_number);
	}
	else if (strcmp(format, "stack") == 0)
	{
		execute_Stack_op(op_name, stack, line_number);
	}

	return (0);
}
