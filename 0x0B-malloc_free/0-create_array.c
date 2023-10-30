#include <stdlib.h>

/**
 * create_array - create an array and fill it
 *
 * @size: size of array
 * @c: char to fill array with
 *
 * Return: pointer to the array or NULL
 */

char *create_array(unsigned int size, char c)
{
	size_t i;
	char *array;

	if (size <= 0)
		return (NULL);

	array = (char *)malloc(size);

	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}

	return (array);
}
