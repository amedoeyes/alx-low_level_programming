#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints size of various data types to stdout
 *
 * Return: 0
 */

int main(void)
{
	int sizeOfChar = sizeof(char);
	int sizeOfInt = sizeof(int);
	int sizeOfLongInt = sizeof(long int);
	int sizeOfLongLongInt = sizeof(long long int);
	int sizeOfFloat = sizeof(float);

	printf("Size of a char: %d byte(s)\n", sizeOfChar);
	printf("Size of an int: %d byte(s)\n", sizeOfInt);
	printf("Size of a long int: %d byte(s)\n", sizeOfLongInt);
	printf("Size of a long long int: %d byte(s)\n", sizeOfLongLongInt);
	printf("Size of a float: %d byte(s)\n", sizeOfFloat);

	return (0);
}
