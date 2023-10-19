#include <ctype.h>

/**
 * rot13 - encodes a string using rot13
 *
 * @s: string to encode
 *
 * Return: pointer to the encoded string
 */

char *rot13(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		int base;

		if (!isalpha(s[i]))
			continue;

		if (islower(s[i]))
			base = 'a';
		else
			base = 'A';

		s[i] = ((s[i] - base + 13) % 26) + base;
	}

	return s;
}
