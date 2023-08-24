#include "monty.h"

/**
 * freeStack - frees the stack to avoid memory leaks
 * @stack: pointer to the head element of the stack
 * Return: nothing
 */
void freeStack(stack_t *stack)
{
	stack_t *current, *elem;

	current = stack;
	while (current != NULL)
	{
		elem = current;
		current = current->next;
		free(elem);
	}
}
