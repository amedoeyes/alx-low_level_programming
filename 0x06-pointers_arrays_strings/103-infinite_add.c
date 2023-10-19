#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * infinite_add - adds two numbers
 *
 * @n1: first number
 * @n2: second number
 * @r: result buffer
 * @size_r: size of the result buffer
 *
 * Return: pointer to the result buffer
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = strlen(n1) - 1;
	int j = strlen(n2) - 1;
	int count = size_r - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int digit1 = i >= 0 ? n1[i] - '0' : 0;
		int digit2 = j >= 0 ? n2[j] - '0' : 0;
		int sum = digit1 + digit2 + carry;
		int k;

		carry = sum / 10;
		sum %= 10;

		for (k = size_r - 1; k > 0; k--)
			r[k] = r[k - 1];

		r[0] = sum + '0';

		i--;
		j--;
		count--;
	}

	if (count < 0)
		return (NULL);

	return (r);
}
