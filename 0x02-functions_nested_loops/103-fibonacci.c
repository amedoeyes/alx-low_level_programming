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
	long sum = 0;
	int i;

	for (i = 0; i < 4000000; i++)
	{
		int temp = n1 + n2;
		n1 = n2;
		n2 = temp;

		if (temp % 2 == 0)
			sum += temp;
	}

	printf("%ld\n", sum);

	return (0);
}
