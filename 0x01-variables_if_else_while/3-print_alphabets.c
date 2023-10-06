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
	int i;
	int j;

	for (i = 0; i < 26; i++)
	{
		putchar('a' + i);
	}

	for (j = 0; j < 26; j++)
	{
		putchar('A' + j);
	}

	putchar('\n');

	return (0);
}
