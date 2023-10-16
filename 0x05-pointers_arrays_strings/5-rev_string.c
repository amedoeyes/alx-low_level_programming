/**
 * string_length - returns the length of a string
 *
 * @s: the string
 *
 * Return: the length of the string
 */

#include <stdio.h>
int string_length(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * rev_string - reverse given string
 *
 * @s: string to reverse
 */

void rev_string(char *s)
{
	char *start = s;
	char *end = s + string_length(s) - 1;
	char temp;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
