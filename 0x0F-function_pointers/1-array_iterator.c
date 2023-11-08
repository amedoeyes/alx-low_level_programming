#include <stddef.h>

/**
 * array_iterator - iterate over an array of integers
 *
 * @array: array
 * @size: size of array
 * @action: callback
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
		action(array[i]);
}
