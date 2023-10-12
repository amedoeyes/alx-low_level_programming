/**
 * _isdigit - checks for digit
 *
 * @c: The character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
