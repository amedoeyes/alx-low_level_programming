/**
 * string_length - returns the length of a string
 *
 * @s: the string
 *
 * Return: the length of the string
 */

#include "main.h"
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
 * puts_half - print second half of string
 *
 * @s: string
 */

void puts_half(char *s)
{
	int length = string_length(s) + 1;
	int i;

	for (i = length / 2; i < length; i++)
	{
		_putchar(s[i]);
	}

	_putchar('\n');
}
