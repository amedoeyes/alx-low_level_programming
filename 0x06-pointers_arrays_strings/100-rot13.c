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
	int i, j;
	char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *alphabet_rot13 =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i]; i++)
	{
		for (j = 0; alphabet[j]; j++)
		{
			if (s[i] == alphabet[j])
			{
				s[i] = alphabet_rot13[j];
				break;
			}
		}
	}

	return (s);
}
