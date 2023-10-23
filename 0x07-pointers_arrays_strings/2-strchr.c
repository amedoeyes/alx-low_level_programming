/**
 * _strchr - locates a character in a string
 *
 * @s: string
 * @c: character
 *
 * Return: pointer to the first occurence of c in s
 */

char *_strchr(char *s, char c)
{
	while (*s != c && *s)
		s++;

	if (*s == c)
		return (s);

	return (0);
}
