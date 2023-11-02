#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenate two strings to a new pointer
 *
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes from string 2 to concatenate
 *
 * Return: pointer to new string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	size_t s1len;
	size_t s2len;

	s1 = s1 ? s1 : "";
	s2 = s2 ? s2 : "";

	s1len = strlen(s1);
	s2len = n < strlen(s2) ? n : strlen(s2);

	concat = (char *)malloc(s1len + s2len + 1);

	if (concat == NULL)
		return (NULL);

	strcpy(concat, s1);
	strncat(concat, s2, s2len);

	return (concat);
}
