/**
 * rev_string - reverse given string
 *
 * @s: string to reverse
 */

#include <string.h>
void rev_string(char *s)
{
	char *start = s;
	char *end = s + strlen(s) - 1;
	char temp;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
