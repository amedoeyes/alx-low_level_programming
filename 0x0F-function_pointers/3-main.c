#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - calculate two numbers
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success, otherwise 98 if invalid number of arguments, 99 if
 * invalid operator, and 100 if division/mod by 0
 *
 */

int main(int argc, char *argv[])
{
	int a, b;
	char *op;
	int result;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = argv[2];

	result = get_op_func(op)(a, b);
	printf("%d\n", result);

	return (0);
}
