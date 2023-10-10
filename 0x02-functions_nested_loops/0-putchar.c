#include "main.h"

/**
 * main - Entry point
 *
 * Description: Prints '_putchar' followed by a new line
 *
 * Return: 0
 */
int main(void)
{
	char *str = "_putchar\n";

	int i = 0;
	char c = str[i];

	while (c != '\0')
	{
		_putchar(c);
		c = str[++i];
	}

	return (0);
}
