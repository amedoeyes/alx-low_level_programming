#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet characters in lowercase in reverse
 *
 * Return: 0
 */

int main(void)
{
	for (int i = 25; i >= 0; i--)
	{
		putchar('a' + i);
	}

	putchar('\n');

	return (0);
}
