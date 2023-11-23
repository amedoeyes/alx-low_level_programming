#include "main.h"

/**
 * flip_bits - counts the number of bits to flip
 *
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long flipped = n ^ m;

	while (flipped)
	{
		count += flipped & 1;
		flipped >>= 1;
	}

	return (count);
}
