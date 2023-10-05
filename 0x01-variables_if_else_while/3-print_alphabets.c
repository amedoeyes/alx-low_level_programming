#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet characters in lowercase and uppercase
 *
 * Return: 0
 */

int main(void)
{
	for (int i = 0; i < 26; i++)
	{
		putchar('a' + i);
	}

	for (int i = 0; i < 26; i++)
	{
		putchar('A' + i);
	}

	putchar('\n');

	return (0);
}
