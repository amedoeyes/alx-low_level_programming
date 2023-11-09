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
		{
			char *s = va_arg(args, char *);

			printf("%s", separator);
			printf("%s", s ? s : "(nil)");
		}
		break;
		}

		separator = ", ";
		i++;
	}

	printf("\n");

	va_end(args);
}
