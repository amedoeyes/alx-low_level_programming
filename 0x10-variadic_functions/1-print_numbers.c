#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * print_numbers - print numbers
 *
 * @separator: separator
 * @n: number of arguments
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	size_t i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		if (separator && i != n - 1)
			printf("%s", separator);
		else
			printf("\n");
	}

	va_end(args);
}
