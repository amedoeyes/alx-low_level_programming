#include <ctype.h>
#include <stdbool.h>
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
 * is_digits - check if string is digits
 *
 * @str: string
 *
 * Return: true or false
 */

bool is_digits(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (false);

	return (true);
}

/**
 * mult - multiplies two string of numbers
 *
 * @a: string 1
 * @b: string 2
 *
 * Return: pointer to result
 */

int *mult(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	int i, j;

	int *result = (int *)calloc(len1 + len2, sizeof(int));

	if (result == NULL)
		exit_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = a[i] - '0';
			int digit2 = b[j] - '0';
			int product = digit1 * digit2;
			int sum = product + result[i + j + 1] + carry;

			result[i + j + 1] = (sum % 10);
			carry = sum / 10;
		}

		result[i + j + 1] = (carry % 10);
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
	char *num1 = argv[1];
	char *num2 = argv[2];
	int *result;
	size_t i;

	if (argc != 3 || !is_digits(num1) || !is_digits(num2))
		exit_error();

	if (*num1 == '0' || *num2 == '0')
	{
		printf("0\n");
		return (0);
	}

	result = mult(num1, num2);

	for (i = 0; i < strlen(num1) + strlen(num2); i++)
		if (result[i] != 0)
			break;

	for (; i < strlen(num1) + strlen(num2); i++)
		printf("%d", result[i]);

	printf("\n");

	return (0);
}
