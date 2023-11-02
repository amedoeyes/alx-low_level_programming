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
	size_t i;

	for (i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (false);

	return (true);
}

/**
 * mult - multiplies two string of numbers
 *
 * @num1: string 1
 * @num2: string 2
 *
 * Return: pointer to result
 */

int *mult(char *num1, char *num2)
{
	size_t len1 = strlen(num1);
	size_t len2 = strlen(num2);
	int i, j;

	int *result = (int *)calloc(len1 + len2, sizeof(int));

	if (result == NULL)
		exit_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';
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
	char *num1;
	char *num2;
	size_t len;
	int *result;
	bool is_non_zero = false;
	size_t i;

	if (argc != 3)
		exit_error();

	num1 = argv[1];
	num2 = argv[2];
	len = strlen(num1) + strlen(num2);

	if (!is_digits(num1) || !is_digits(num2))
		exit_error();

	result = mult(num1, num2);

	for (i = 0; i < len; i++)
	{
		if (result[i] != 0)
			is_non_zero = true;

		if (is_non_zero)
			printf("%d", result[i]);
	}

	if (!is_non_zero)
		printf("0");

	printf("\n");

	free(result);

	return (0);
}
