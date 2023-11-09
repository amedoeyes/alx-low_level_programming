#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * print_all - print
 *
 * @format: types of arguments
 */

void print_all(const char *const format, ...)
{
	va_list args;
	size_t i = 0;
	const char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s", separator);
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			printf("%s", separator);
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%s", separator);
			printf("%f", va_arg(args, double));
			break;
		case 's':
			printf("%s", separator);
			printf("%s", va_arg(args, char *));
			break;
		}

		separator = ", ";
		i++;
	}

	printf("\n");

	va_end(args);
}
