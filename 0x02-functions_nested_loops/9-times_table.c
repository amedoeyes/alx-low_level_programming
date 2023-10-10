#include "main.h"

/**
 * times_table - prints the multiplication table from 0 to 9
 */
void times_table(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		int j;

		for (j = 0; j <= 9; j++)
		{
			int r = i * j;

			if (r <= 9 && j != 0)
			{
				_putchar(' ');
			}

			if (r >= 10)
			{
				_putchar('0' + (r / 10));
			}

			_putchar('0' + (r % 10));

			if (j < 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}

		_putchar('\n');
	}
}
