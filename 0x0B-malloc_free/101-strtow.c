#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * get_words - get words info from string
 *
 * @str: string
 * @count: pointer to count words
 * @lengths: pointer to words lengths
 * @positions: pointer to words positions
 *
 */

void get_words(char *str, int *count, int **lengths, int **positions)
{
	int i, j = 0;
	int words_count = 0, *words_lengths, *words_positions;

	for (i = 0; str[i]; i++)
	{
		if (isspace(str[i]))
			continue;
		words_count++;
		while (str[i] && !isspace(str[i]))
			i++;
	}

	words_lengths = (int *)malloc(sizeof(int) * words_count);
	words_positions = (int *)malloc(sizeof(int) * words_count);
	if (words_lengths == NULL || words_positions == NULL)
	{
		free(words_lengths);
		free(words_positions);
		return;
	}

	for (i = 0; str[i]; i++)
	{
		int word_len = 0;

		if (isspace(str[i]))
			continue;
		words_positions[j] = i;
		while (str[i] && !isspace(str[i]))
		{
			word_len++;
			i++;
		}
		words_lengths[j] = word_len;
		j++;
	}

	*count = words_count;
	*lengths = words_lengths;
	*positions = words_positions;
}

/**
 * strtow - convert string to array of words
 *
 * @str: string
 *
 * Return: pointer to array
 */

char **strtow(char *str)
{
	char **array;
	int words_count, *words_length, *words_positions;
	int i, j, k;

	if (str == NULL || *str == '\0')
		return (NULL);

	get_words(str, &words_count, &words_length, &words_positions);

	array = malloc((words_count + 1));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < words_count; i++)
	{
		array[i] = malloc(words_length[i] + 1);

		if (array[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(array[k]);

			free(array);
			return (NULL);
		}

		j = 0;
		k = words_positions[i];

		while (str[k] && !isspace(str[k]))
			array[i][j++] = str[k++];

		array[i][j] = '\0';
	}

	array[i] = NULL;

	return (array);
}
