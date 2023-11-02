#include <stdlib.h>
#include <string.h>

/**
 * _realloc - reallocate memory block
 *
 * @ptr: pointer to memory block
 * @old_size: size of memory block
 * @new_size: new size of memory block
 *
 * Return: pointer to new memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
