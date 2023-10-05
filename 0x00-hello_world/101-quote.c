#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints 'and that piece of art is useful" - Dora Korpar,
 * 2015-10-19' to stderr
 *
 * Return: 1
 */

int main(void)
{
	perror("and that piece of art is useful\" - Dora Korpar, 2015-10-19");
	return (1);
}
