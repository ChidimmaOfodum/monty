#include "monty.h"

void do_nothing(void);
glob stream;

/**
 * main - Entry point of program
 * @ac: argument count
 * @av: argument vector
 * Return: success 0
 */
int main(int ac, char **av)
{
	FILE *o = NULL;
	char *op_name, *op_data, lineptr[SIZE], *delim = " \n\t\r";
	int line_number = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	o = fopen(av[1], "r");
	if (!o)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", av[1]);
		exit(EXIT_FAILURE);
	}
	stream.o = o;

	while (fgets(lineptr, SIZE, o) != NULL)
	{
		line_number++;

		op_name = strtok(lineptr, delim);
		op_data = strtok(NULL, delim);

		if (op_name)
		{
			stream.data = op_data;
			execute_op(op_name, &stack, line_number);
		}
	}

	fclose(o);
	freeStack(stack);

	return (0);
}
