/**
 * _strcpy - copy the string pointed to by src to dest
 *
 * @src: source string pointer
 * @dest: destination string pointer
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *dest_ptr = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (dest_ptr);
}
