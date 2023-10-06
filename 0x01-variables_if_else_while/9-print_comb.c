#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints base 10 seperated by commas
 *
 * Return: 0
 */

int main(void)
{

	for (int i = 0; i < 10; i++)
	{
		putchar('0' + i);

		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
