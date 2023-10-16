#include <stdio.h>

/**
 * print_array - print the elements of array of integers
 *
 * @a: integer array
 * @n: length of array
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		if (i >= n - 1)
			continue;

		printf(", ");
	}

	printf("\n");
}
