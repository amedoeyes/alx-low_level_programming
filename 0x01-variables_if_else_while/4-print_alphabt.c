#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet characters except for 'e' and 'q' in
 * lowercase
 *
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = 0; i < 26; i++)
	{
		if (i == 4 || i == 16)
			continue;

		putchar('a' + i);
	}

	putchar('\n');

	return (0);
}
