#include <stdarg.h>
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
	char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", separator, va_arg(args, int));
			break;
		case 'i':
			printf("%s%d", separator, va_arg(args, int));
			break;
		case 'f':
			printf("%s%f", separator, va_arg(args, double));
			break;
		case 's':
		{
			char *s = va_arg(args, char *);

			if (s)
				printf("%s%s", separator, s);
			else
				printf("%s(nil)", separator);
		}
		break;
		}

		separator = ", ";
		i++;
	}

	printf("\n");

	va_end(args);
}
