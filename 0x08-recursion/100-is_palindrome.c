#include <string.h>

/**
 * is_palindrome_helper - helper function to check if a string is a palindrome
 *
 * @str: string
 * @low: low index
 * @high: high index
 *
 * Return: 1 if palindrome otherwise 0
 */

int is_palindrome_helper(char *str, int low, int high)
{
	if (low >= high)
		return (1);

	if (str[low] != str[high])
		return (0);

	return (is_palindrome_helper(str, low + 1, high - 1));
}

/**
 * is_palindrome - check if a string is a palindrome
 *
 * @str: string
 *
 * Return: 1 if palindrome otherwise 0
 */

int is_palindrome(char *str)
{
	if (*str == '\0')
		return (1);

	return (is_palindrome_helper(str, 0, strlen(str) - 1));
}
