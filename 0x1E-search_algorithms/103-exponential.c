#include "search_algos.h"

/**
 * bs - searches for a value in a sorted array of integers using the
 * Binary search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @left: Index of the left bound
 * @right: Index of the right bound
 * @value: Value to search for
 *
 * Return: The first index where value is located or -1 if value is not present
 */

static int bs(int *array, size_t left, size_t right, int value)
{
	size_t i, mid;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = (left + right) / 2;
		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}

	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located or -1 if value is not present
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, min;

	if (array == NULL)
		return (-1);

	for (bound = 1; bound < size && array[bound] < value; bound *= 2)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
	}

	min = bound < size - 1 ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, min);

	return (bs(array, bound / 2, min, value));
}
