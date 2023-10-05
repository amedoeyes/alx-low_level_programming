#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints base 10 numbers
 *
 * Return: 0
 */

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		putchar('0' + i);
	}

	putchar('\n');

	return (0);
}
