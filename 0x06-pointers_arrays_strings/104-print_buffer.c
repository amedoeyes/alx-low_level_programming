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
	int i;

	for (i = 0; i < size; i += SIZE)
	{
		int j;

		printf("%08x: ", i);

		for (j = 0; j < SIZE / 2; j++)
		{
			if (i + j * 2 >= size)
			{
				printf("     ");
				continue;
			}

			printf("%02x", buffer[i + j * 2]);
			printf("%02x", buffer[i + j * 2 + 1]);

			printf(" ");
		}

		for (j = 0; j < SIZE; j++)
		{
			if (i + j >= size)
				break;

			printf("%c", isprint(buffer[i + j]) ? buffer[i + j] : '.');
		}

		printf("\n");
	}
}
