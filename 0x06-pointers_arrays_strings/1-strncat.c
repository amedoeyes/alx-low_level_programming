/**
 * _strncat - concatenates two strings
 *
 * @dest: first string
 * @src: second string
 * @n: number of bytes
 *
 * Return: pointer to the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{

	char *ptr = dest;
	int i;

	while (*ptr)
		ptr++;

	for (i = 0; src[i] && i < n; i++)
		*ptr++ = src[i];

	return (dest);
}
