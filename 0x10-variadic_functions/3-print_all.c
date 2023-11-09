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

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
			{
				char *s = va_arg(args, char *);

				if (!s)
					s = "(nil)";

				printf("%s", s);

				break;
			}
			default:
				i++;
				continue;
		}

		if (format[i + 1])
			printf(", ");

		i++;
	}
	printf("\n");
	va_end(args);
}
