#include "main.h"

/**
 * string_length - returns the length of a string
 *
 * @s: the string
 *
 * Return: the length of the string
 */

int string_length(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * print_rev - print given string in reverse
 *
 * @s: string
 */

void print_rev(char *s)
{
	int i = 0;

	for (i = string_length(s) - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	_putchar('\n');
}
