#include <string.h>
#include <unistd.h>

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
	char *str = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(STDERR_FILENO, str, strlen(str));
	return (1);
}
