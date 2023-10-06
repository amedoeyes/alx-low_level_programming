#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints every possible combination of two two0digits
 *
 * Return: 0
 */

int main(void)
{

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i >= j)
				continue;

			putchar('0' + (i / 10));
			putchar('0' + (i % 10));
			putchar(' ');
			putchar('0' + (j / 10));
			putchar('0' + (j % 10));

			if (i == 98 && j == 99)
				continue;

			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
