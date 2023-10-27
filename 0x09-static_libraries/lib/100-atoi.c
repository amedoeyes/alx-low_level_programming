#include <ctype.h>

/**
 * _atoi - convert string to an integer
 *
 * @s: string to convert
 *
 * Return: integer value of the string
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (isdigit(s[i]))
		{
			while (isdigit(s[i]))
			{
				result = result * 10 + (s[i] - '0');

				i++;
			}

			result *= sign;

			return (result);
		}
	}

	return (0);
}
