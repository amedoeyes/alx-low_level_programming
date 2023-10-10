#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print the sum of even fibonacci numbers below 4000000
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	long n1 = 0;
	long n2 = 1;
	long r = 0;
	long sum = 0;

	while (r < 4000000)
	{
		r = n1 + n2;
		n1 = n2;
		n2 = r;

		if (r % 2 == 0)
			sum += r;
	}

	printf("%ld\n", sum);

	return (0);
}
