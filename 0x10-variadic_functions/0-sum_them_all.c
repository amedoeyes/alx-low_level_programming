#include <stdarg.h>
#include <stddef.h>

/**
 * sum_them_all - sum of all parameters
 *
 * @n: number of arguments
 *
 * Return: sum of arguments
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum = 0;
	size_t i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}

	va_end(args);

	return (sum);
}
