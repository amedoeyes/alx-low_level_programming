#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenate arguments to string
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to concatenated string or NULL
 */

char *argstostr(int ac, char **av)
{
	char *concat;
	int concatlen;
	int i;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 1; i < ac; i++)
	{
		concatlen += strlen(av[i]) + 1;
	}

	concat = (char *)malloc(concatlen + 1);

	if (concat == NULL)
		return (NULL);

	for (i = 1; i < ac; i++)
	{
		strcat(concat, av[i]);
		strcat(concat, "\n");
	}

	return (concat);
}
