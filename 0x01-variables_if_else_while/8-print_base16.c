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

	for (int i = 0; i < 10; i++)
	{
		putchar('0' + i);
	}

	for (int i = 0; i < 6; i++)
	{
		putchar('a' + i);
	}

	putchar('\n');

	return (0);
}
