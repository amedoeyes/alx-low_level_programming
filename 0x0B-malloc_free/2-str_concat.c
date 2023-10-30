#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenate two strings
 *
 * @str1: the first string
 * @str2: the second string
 *
 * Return: pointer to the concatenated string
 */

char *str_concat(char *str1, char *str2)
{
	char *concat = (char *)malloc(strlen(str1) + strlen(str2));

	strcpy(concat, str1);
	strcat(concat, str2);

	return (concat);
}
