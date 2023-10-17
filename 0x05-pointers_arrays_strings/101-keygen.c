#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for the
 *        program 101-crackme.
 *
 * Return: Always 0.
 */

int main(void)
{
	int sum = 0;
	char c;

	srand(time(NULL));

	do {
		c = '!' + rand() % ('!' - '~' + 1);
		sum = sum + c;

		putchar(c);
	} while ((sum + c) < 2772);

	putchar(2772 - sum);

	return (0);
}
