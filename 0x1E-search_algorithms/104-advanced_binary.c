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

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	mid = (left + right) / 2;

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	else if (array[mid] < value)
		return (bs(array, mid + 1, right, value));
	else
		return (bs(array, left, mid, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers using
 * the Binary search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located or -1 if value is not present
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (bs(array, 0, size - 1, value));
}
