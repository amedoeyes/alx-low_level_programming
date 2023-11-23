#include "main.h"

/**
 * binary_to_uint - converts binary to unsigned int
 *
 * @b: binary string
 *
 * Return: converted unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int len;
	int i;

	if (b == NULL)
		return (0);

	len = strlen(b);

	for (i = len - 1; i >= 0; i--)
	{
		int digit = b[i] - '0';

		if (b[i] != '0' && b[i] != '1')
			return (0);

		res += digit << (len - i - 1);
	}

	return (res);
}
