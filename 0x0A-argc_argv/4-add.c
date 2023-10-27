#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - add positive numbers
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success, 1 if error
 */

int main(int argc, char *argv[])
{
	int result = 0;
	int i;
	int j;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		result += atoi(argv[i]);
	}

	printf("%d\n", result);

	return (0);
}
