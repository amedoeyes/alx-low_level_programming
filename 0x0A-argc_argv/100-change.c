#include <stdio.h>
#include <stdlib.h>

/**
 * main - calculate the minimum number of coins to make change
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success, 1 if error
 */

int main(int argc, char *argv[])
{
	int coins = 0;
	int change;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	change = atoi(argv[1]);

	while (change > 0)
	{
		if (change >= 25)
			change -= 25;
		else if (change >= 10)
			change -= 10;
		else if (change >= 5)
			change -= 5;
		else if (change >= 2)
			change -= 2;
		else if (change >= 1)
			change -= 1;

		coins++;
	}
	printf("%d\n", coins);

	return (0);
}
