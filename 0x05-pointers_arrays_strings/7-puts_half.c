#include "main.h"
#include <string.h>

/**
 * puts_half - print second half of string
 *
 * @s: string
 */

void puts_half(char *s)
{
	int length = strlen(s) + 1;
	int i;

	for (i = length / 2; i < length - 1; i++)
	{
		_putchar(s[i]);
	}

	_putchar('\n');
}
