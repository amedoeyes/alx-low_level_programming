/**
 * print_diagsums - print the sum of both diagonals of a square matrix
 *
 * @a: matrix
 * @size: size of matrix
 */

#include <stdio.h>
void print_diagsums(int *a, int size)
{
	int i;
	unsigned int sum1 = 0;
	unsigned int sum2 = 0;

	for (i = 0; i < size; i++)
		sum1 += a[i * size + i];

	for (i = size - 1; i >= 0; i--)
		sum2 += a[(size - i) * (size - 1)];

	printf("%d, %d\n", sum1, sum2);
}
