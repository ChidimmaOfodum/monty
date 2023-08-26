#include "monty.h"

/**
 * execute_op - executes a particular function if valid
 * @op_name: operation name
 * @stack: pointer to topmost stack element
 * @line_number: file line number
 * Return: void
 */
void execute_op(char *op_name, stack_t **stack, unsigned int line_number)
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
