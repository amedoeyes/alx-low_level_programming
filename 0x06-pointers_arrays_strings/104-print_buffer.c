#include <ctype.h>
#include <stdio.h>

#define SIZE 10

/**
 * print_buffer - print buffer
 *
 * @buffer: buffer
 * @size: size of buffer
 */

void print_buffer(char *buffer, int size)
{
	int i, j;

	for (i = 0; i < size; i += SIZE)
	{
		printf("%08x: ", i);

		for (j = i; j < i + SIZE; j += 2)
		{
			if (j >= size)
			{
				printf("     ");
				continue;
			}

			printf("%02x", buffer[j]);

			if (j + 1 < size)
				printf("%02x", buffer[j + 1]);
			else
				printf("  ");

			printf(" ");
		}

		for (j = i; j < i + SIZE && j < size; j++)
			printf("%c", isprint(buffer[j]) ? buffer[j] : '.');

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
