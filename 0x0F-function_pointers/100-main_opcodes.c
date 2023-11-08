#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the opcodes of main
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success, otherwise 1 if invalid number of arguments, or 2 if
 * negative bytes
 */

int main(int argc, char *argv[])
{
	int bytes;
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < bytes; i++)
	{
		printf("%02x", *((char *)main + i) & 0xff);

		if (i != bytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
