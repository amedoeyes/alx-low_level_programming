#include "include/main.h"

int main(void)
{

	char *str = "_putchar\n";

	int i = 0;
	char c = str[i];

	while (c != '\0')
	{
		_putchar(c);
		c = str[++i];
	}

	return 0;
}
