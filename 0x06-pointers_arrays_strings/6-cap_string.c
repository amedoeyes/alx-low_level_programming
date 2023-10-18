#include <stdbool.h>
#include <stdio.h>

/**
 * cap_string - capitalizes all words of a string
 * @str: string
 *
 * Return: pointer to the changed string
 */

char *cap_string(char *str)
{
	int i;
	int capitalize = 1;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == ',' || str[i] == ';' || str[i] == '.' || str[i] == '!' ||
			str[i] == '?' || str[i] == '"' || str[i] == '(' || str[i] == ')' ||
			str[i] == '{' || str[i] == '}')
		{
			capitalize = 1;
			continue;
		}

		if (capitalize && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			capitalize = 0;
		}
		else
		{
			capitalize = 0;
		}
	}

	return (str);
}
