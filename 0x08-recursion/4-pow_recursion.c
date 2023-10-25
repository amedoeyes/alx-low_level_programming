/**
 * _pow_recursion - calculate the power of a number
 *
 * @x: base
 * @y: exponent
 *
 * Return: power of x to y
 */

int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);

	if (y < 0)
		return (-1);

	return (_pow_recursion(x, y - 1) * x);
}
