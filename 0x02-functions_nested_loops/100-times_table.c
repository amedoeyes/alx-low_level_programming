#include "main.h"

/**
 * print_times_table - prints the multiplication table from 0 to n
 * @n: the size of the table
 */
void print_times_table(int n)
{
	int i, j;

	if (n > 15 || n < 0)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int r = i * j;

			if (r < 10 && j > 0)
				_putchar(' ');

			if (r < 100 && j > 0)
				_putchar(' ');

			if (r > 99)
				_putchar((r / 100) + '0');

			if (r > 9)
				_putchar((r / 10) % 10 + '0');

			_putchar((r % 10) + '0');

			if (j == n)
				continue;

			_putchar(',');
			_putchar(' ');
		}

		_putchar('\n');
	}
}
