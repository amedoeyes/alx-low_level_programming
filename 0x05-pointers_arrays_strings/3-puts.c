#include "main.h"

/**
 * _puts - print given string
 *
 * @s: string
 */

void _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	_putchar('\n');
}
