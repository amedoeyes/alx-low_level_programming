/**
 * _isupper - checks for uppercase character
 *
 * @c: The character to be checked
 *
 * Return: 1 if uppercase otherwise 0
 */

int _isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	return (0);
}
