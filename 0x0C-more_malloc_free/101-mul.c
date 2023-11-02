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

	char *result = (char *)malloc(len1 + len2 + 1);

	if (result == NULL)
		exit_error();

	memset(result, '0', len1 + len2);
	result[len1 + len2] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = a[i] - '0';
			int digit2 = b[j] - '0';
			int product = digit1 * digit2;
			int sum = product + (result[i + j + 1] - '0');

			result[i + j + 1] = (sum % 10) + '0';
			result[i + j] = (sum / 10) + '0';
		}
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
	int i;

	if (argc != 3)
		exit_error();

	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);

	for (i = 0; i < len1; i++)
		if (!isdigit(argv[1][i]))
			exit_error();

	for (i = 0; i < len2; i++)
		if (!isdigit(argv[2][i]))
			exit_error();

	result = mult(argv[1], argv[2]);

	printf("%s\n", result);

	return (0);
}
