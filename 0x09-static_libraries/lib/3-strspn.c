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
 * _strspn - get length of prefix substring
 *
 * @s: string
 * @accept: string
 *
 * Return: length
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;

	while (strcont(accept, *s++))
		len++;

	return (len);
}
