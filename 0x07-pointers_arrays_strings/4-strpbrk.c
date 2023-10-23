/**
 * strcont - check if a string contains a character
 *
 * @s: string
 * @c: character
 *
 * Return: 1 if yes otherwise 0
 */

int strcont(char *s, char c)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (1);
	}

	return (0);
}

/**
 * _strpbrk - search a string for any of a set of bytes
 *
 * @s: string
 * @accept: bytes
 *
 * Return: pointer to the first byte in s or NULL
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s && !strcont(accept, *s))
		s++;

	if (*s)
		return (s);

	return (0);
}
