#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Description: Prints to stdout weather random number is positive or negative
 *
 * Return: 0
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	char *out;

	if (n > 0)
		out = "positive";
	else if (n == 0)
		out = "zero";
	else
		out = "negative";

	printf("%d is %s\n", n, out);

	return (0);
}
