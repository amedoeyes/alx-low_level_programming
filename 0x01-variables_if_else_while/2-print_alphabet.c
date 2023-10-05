#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet characters in lowercase
 *
 * Return: 0
 */

int main(void)
{
	for (int i = 0; i < 26; i++)
	{
		putchar('a' + i);
	}

	putchar('\n');

	return (0);
}
