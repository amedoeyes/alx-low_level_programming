#include <stdio.h>
#define MAX 10000000000

/**
 * main - Entry point
 *
 * Description: Print the first 98 fibonacci numbers
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	unsigned long n1 = 0, n2 = 1, r, n1h1, n1h2, n2h1, n2h2, h1, h2;

	for (i = 0; i < 92; i++)
	{
		r = n1 + n2;
		n1 = n2;
		n2 = r;
		printf("%lu, ", r);
	}

	n1h1 = n1 / MAX;
	n1h2 = n1 % MAX;
	n2h1 = n2 / MAX;
	n2h2 = n2 % MAX;

	for (i = 93; i < 99; i++)
	{
		h1 = n1h1 + n2h1;
		h2 = n1h2 + n2h2;

		if (h2 > MAX)
		{
			h1++;
			h2 %= MAX;
		}

		n1h1 = n2h1;
		n1h2 = n2h2;
		n2h1 = h1;
		n2h2 = h2;

		printf("%lu%lu", h1, h2);

		if (i < 98)
			printf(", ");
		else
			printf("\n");
	}
	return (0);
}
