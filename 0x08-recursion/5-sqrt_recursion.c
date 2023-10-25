/**
 * _sqrt_helper - calculates the square root of a number
 *
 * @n: number
 * @x: number
 *
 * Return: square root
 */

int _sqrt_helper(int n, int x)
{
	int g = 0.5 * (x + n / x);

	if (x - g == 0)
		return (g);

	return (_sqrt_helper(n, g));
}

/**
 * _sqrt_recursion - calculates the square root of a number
 *
 * @n: number
 *
 * Return: square root
 */

int _sqrt_recursion(int n)
{
	int sqrt;

	if (n < 0)
		return (-1);

	if (n == 0)
		return (0);

	sqrt = _sqrt_helper(n, n);

	if (sqrt * sqrt != n)
		return (-1);

	return (sqrt);
}
