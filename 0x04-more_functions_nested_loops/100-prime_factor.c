#include <stdio.h>

/**
 * isPrime - checks if a number is prime
 *
 * @n: The number to be checked
 *
 * Return: 1 if prime otherwise 0
 */

int isPrime(long n)
{
	long i;

	if (n <= 1)
		return (0);

	if (n <= 3)
		return (1);

	if (n % 2 == 0 || n % 3 == 0)
		return (0);

	for (i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (0);
	}

	return (1);
}

/**
 * main - Prints the largest prime factor of the number 612852475143
 *
 * Return: 0
 */

int main(void)
{
	long n = 612852475143;
	long i = 2;
	long lpf = 0;

	while (n > 1)
	{
		while (n % i == 0 && isPrime(i))
		{
			n = n / i;
			lpf = i;
		}

		i++;
	}

	printf("%ld\n", lpf);

	return (0);
}
