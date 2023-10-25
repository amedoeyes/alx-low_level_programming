/**
 * is_prime_helper - helper function to check if a number is prime
 *
 * @n: number
 * @i: iterator
 *
 * Return: 1 if prime otherwise 0
 */

int is_prime_helper(int n, int i)
{
	if (n < 2)
		return (0);

	if (n == 2 || n == 3)
		return (1);

	if (n % 2 == 0 || n % 3 == 0)
		return (0);

	if (i >= n)
		return (1);

	if (n % i == 0 || n % (i + 2) == 0)
		return (0);

	return (is_prime_helper(n, i + 6));
}

/**
 * is_prime_number - check if a number is prime
 *
 * @n: number
 *
 * Return: 1 if prime otherwise 0
 */

int is_prime_number(int n)
{
	return (is_prime_helper(n, 5));
}
