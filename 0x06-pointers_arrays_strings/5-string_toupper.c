/**
 * string_toupper - change all lowercase characters to uppercase
 *
 * @s: string
 *
 * Return: pointer to the changed string
 */

char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}

	return (s);
}
