#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints every possible combination of three digits
 *
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		int j;

		for (j = 0; j < 10; j++)
		{
			int k;

			for (k = 0; k < 10; k++)
			{
				if (i >= j || i >= k || j >= k)
					continue;

				putchar('0' + i);
				putchar('0' + j);
				putchar('0' + k);

				if (i == 7 && j == 8 && k == 9)
					continue;

				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
