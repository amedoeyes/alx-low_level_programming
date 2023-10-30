#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * get_word_count - count words from string
 *
 * @str: string
 *
 * Return: word count
 */

int get_word_count(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		if (isspace(str[i]))
		{
			i++;
			continue;
		}

		count++;

		while (str[i] && !isspace(str[i]))
			i++;
	}

	return (count);
}

/**
 * get_word - get word position and length
 *
 * @str: string
 * @word_pos: position pointer
 * @word_len: length pointer
 */

void get_word(char *str, int *word_pos, int *word_len)
{
	static int str_pos;
	int pos;
	int len = 0;

	while (str[str_pos])
	{
		if (isspace(str[str_pos]))
		{
			str_pos++;
			continue;
		}

		pos = str_pos;

		while (str[str_pos] && !isspace(str[str_pos]))
		{
			len++;
			str_pos++;
		}

		break;
	}

	*word_pos = pos;
	*word_len = len;
}

/**
 * push_word - push word to array
 *
 * @array: array
 * @index: array index
 * @str: string
 * @word_pos: word position
 * @word_len: word length
 */

void push_word(char **array, int index, char *str, int word_pos, int word_len)
{
	int i;
	int j = 0;

	for (i = word_pos; i < word_len + word_pos; i++, j++)
	{
		array[index][j] = str[i];
	}

	array[index][j] = '\0';
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
	int words_count;
	int word_len;
	int word_pos;
	int i, j;

	if (str == NULL)
		return (NULL);

	words_count = get_word_count(str);

	if (words_count == 0)
		return (NULL);

	array = malloc(sizeof(char *) * (words_count + 1));

	if (array == NULL)
		return (NULL);

	for (i = 0; i < words_count; i++)
	{
		get_word(str, &word_pos, &word_len);

		array[i] = (char *)malloc(word_len + 1);

		if (array[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(array[j]);

			free(array);
			return (NULL);
		}

		push_word(array, i, str, word_pos, word_len);
	}

	array[i] = NULL;

	return (array);
}
