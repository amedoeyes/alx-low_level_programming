#include <stdlib.h>
#include <string.h>

/**
 * _strdup - duplicate a string
 *
 * @str: string
 *
 * Return: pointer to duplicate or NULL
 */

char *_strdup(char *str)
{
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = (char *)malloc(strlen(str) + 1);

	if (dup == NULL)
		return (NULL);

	strcpy(dup, str);

	return (dup);
}
