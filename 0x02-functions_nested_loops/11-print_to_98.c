/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 * Return: void
 */
#include <stdio.h>
void print_to_98(int n)
{
	int i;

	for (i = n; i <= 98; i++)
	{
		printf("%d, ", i);
	}

	for (i = n; i >= 98; i--)
	{
		printf("%d, ", i);
	}

	printf("\n");
}
