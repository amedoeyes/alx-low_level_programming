#include <stddef.h>
#include <stdlib.h>

/**
 * _calloc - allocate memory for an array
 *
 *  @nmemb: number of elements
 *  @size: size of each element
 *
 *  Return: pointer to allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	arr = malloc(nmemb * size);

	if (arr == NULL)
		return (NULL);

	return (arr);
}
