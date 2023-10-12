#include "main.h"

/**
 * print_line - print a line
 *
 * @n: The length of the line
 */

void print_line(int n)
{
	while (n-- > 0)
	{
		_putchar('_');
	}

	_putchar('\n');
}
