#include <stddef.h>
#include <stdlib.h>

/**
 * array_range - create an array of integers
 *
 * @min: min value
 * @max: max value
 *
 * Return: pointer to array
 */

int *array_range(int min, int max)
{
	int *arr;
	int i;

	if (min > max)
		return (NULL);

	arr = (int *)malloc(sizeof(int) * (max - min + 1));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i + min <= max; i++)
	{
		arr[i] = min + i;
	}

	return (arr);
}
