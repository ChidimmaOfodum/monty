#include "monty.h"

/**
 * isInteger - Checks if a string is comprised of digits and signs
 * @data: data string
 * Return: 0 if it is, else -1
 */
int isInteger(char *data)
{
	int i, j;
	char int_sign[13] = "0123456789+-";

	for (i = 0; data[i] != '\0'; i++)
	{
		for (j = 0; int_sign[j] != '\0'; j++)
		{
			if (data[i] == int_sign[j])
				break;
		}
		if (int_sign[j] == '\0')
			return (-1);
	}

	return (0);
}
