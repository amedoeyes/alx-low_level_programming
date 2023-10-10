/**
 * print_last_digit - prints the last digit of a number
 * @n: the number
 * Return: the last digit
 */
#include "main.h"
int print_last_digit(int n)
{
	int last_digit = n % 10 < 0 ? -n % 10 : n % 10;

	_putchar('0' + last_digit);

	return (last_digit);
}
