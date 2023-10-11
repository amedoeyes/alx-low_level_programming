#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print the first 50 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long n1 = 0;
	long n2 = 1;
	long r;
	int i;

	for (i = 0; i < 50; i++)
	{
		r = n1 + n2;
		n1 = n2;
		n2 = r;

		printf("%ld", r);

		if (i < 49)
			printf(", ");
		else
			printf("\n");
	}

	return (0);
}
