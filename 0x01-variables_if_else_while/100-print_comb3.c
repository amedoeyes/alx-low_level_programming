#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints every possible combination of two digits
 *
 * Return: 0
 */

int main(void)
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i >= j)
				continue;

			putchar('0' + i);
			putchar('0' + j);

			if (i == 8 && j == 9)
				continue;

			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
