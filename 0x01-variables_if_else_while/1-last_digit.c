#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Description: Prints weather last digit of a random number is
 * greater than 5, 0, or less than 6
 *
 * Return: 0
 */

int main(void)
{
	int n;
	char *out;
	int lastDigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastDigit = n % 10;

	if (lastDigit > 5)
		out = "and is greater than 5";
	else if (lastDigit == 0)
		out = "and is 0";
	else
		out = "and is less than 6 and not 0";

	printf("Last digit of %d is %d %s\n", n, lastDigit, out);

	return (0);
}
