#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers using the
 * Jump search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located or -1 if value is not present
 */

int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, prev;

	if (array == NULL)
		return (-1);

	jump = sqrt(size);
	prev = 0;

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

		prev += jump;

		if (prev >= size)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev - jump, prev);
	for (i = prev - jump; i <= prev; i++)
	{
		if (i >= size)
			break;

		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
	}

	return (-1);
}
