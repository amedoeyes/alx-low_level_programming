/**
 * _isupper - checks for uppercase character
 *
 * @c: The character to be checked
 *
 * Return: 1 if c is uppercase, 0 otherwise
 */

int _isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	return (0);
}
