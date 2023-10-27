/**
 * _strcat - concatenates two strings
 *
 * @dest: first string
 * @src: second string
 *
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest;
	int i;

	while (*ptr)
		ptr++;

	for (i = 0; src[i]; i++)
		*ptr++ = src[i];

	return (dest);
}
