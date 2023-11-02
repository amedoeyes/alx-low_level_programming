#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_error - exit with error
 */

void exit_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * mult - multiplies two string of numbers
 *
 * @a: string 1
 * @b: string 2
 *
 * Return: pointer to result
 */

char *mult(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	int i, j;

	char *result = (char *)malloc(len1 + len2);

	if (result == NULL)
		exit_error();

	memset(result, '0', len1 + len2);

	for (i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = a[i] - '0';
			int digit2 = b[j] - '0';
			int product = digit1 * digit2;
			int sum = product + (result[i + j + 1] - '0') + carry;

			result[i + j + 1] = (sum % 10) + '0';
			carry = sum / 10;
		}

		result[i + j + 1] = (carry % 10) + '0';
	}

	return (result);
}

/**
 * main - multiplies two numbers
 *
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 if success otherwise 98
 */

int main(int argc, char *argv[])
{
	char *result;
	int len1, len2;
	char *num1, *num2;
	int i;

	if (argc != 3)
		exit_error();

	num1 = argv[1];
	num2 = argv[2];

	if (*num1 == '0' || *num2 == '0')
	{
		printf("0\n");
		return (0);
	}

	len1 = strlen(num1);
	len2 = strlen(num2);

	for (i = 0; i < len1; i++)
		if (!isdigit(num1[i]))
			exit_error();

	for (i = 0; i < len2; i++)
		if (!isdigit(num2[i]))
			exit_error();

	result = mult(num1, num2);

	while (*result == '0')
		result++;

	printf("%s\n", result);

	return (0);
}
