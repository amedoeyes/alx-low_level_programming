#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints base 16 characters
 *
 * Return: 0
 */

int main(void)
{

	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		putchar('0' + i);
	}

	for (j = 0; j < 6; j++)
	{
		putchar('a' + j);
	}

	putchar('\n');

	return (0);
}
