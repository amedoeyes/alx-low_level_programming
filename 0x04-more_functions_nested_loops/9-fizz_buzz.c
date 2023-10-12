#include <stdio.h>
#include <string.h>

/**
 * main - print fizz if n is multiple of 3 or buzz if multiple of 5 or fizzbuzz
 * if multiple of 3 and 5
 *
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		char out[8] = "";

		if (i % 3 == 0)
			strcat(out, "Fizz");

		if (i % 5 == 0)
			strcat(out, "Buzz");

		if (out[0] != '\0')
			printf("%s", out);
		else
			printf("%d", i);

		if (i != 100)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
