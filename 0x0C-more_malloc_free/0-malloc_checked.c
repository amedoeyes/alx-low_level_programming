#include <stdlib.h>

/**
 * malloc_checked - allocate memory and exit program if it fails
 *
 * @b: number of bytes
 *
 * Return: pointer to allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
