#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_op_func - get operator function
 *
 * @s: operator
 *
 * Return: operator function
 */

OpFunc get_op_func(char *s)
{
	op_t ops[] = {{"+", op_add}, {"-", op_sub}, {"*", op_mul},
				  {"/", op_div}, {"%", op_mod}, {NULL, NULL}};
	int i = 0;

	while (ops[i].op != NULL)
	{
		if (strcmp(s, ops[i].op) == 0)
			return (ops[i].f);

		i++;
	}

	printf("Error\n");
	exit(99);
}
