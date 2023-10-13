#include "main.h"

/**
 * print_number - prints an integer
 *
 * @n: The number to be printed
 */

void print_number(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}

	if (i / 10)
		print_number(i / 10);

	_putchar('0' + i % 10);
}
