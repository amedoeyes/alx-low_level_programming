#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * print_strings - prints strings
 *
 * @separator: separator
 * @n: number of arguments
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	size_t i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		char *s = va_arg(args, char *);

		printf("%s", s ? s : "(nil)");

		if (separator && i != n - 1)
			printf("%s", separator);
	}

	printf("\n");

	va_end(args);
}
