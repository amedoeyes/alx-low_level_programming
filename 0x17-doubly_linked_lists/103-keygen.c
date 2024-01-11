#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates a key for crackme5
 *
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char **argv)
{
	char *chars =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7];
	char *input_str;
	size_t len;
	size_t i;
	size_t j;

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	input_str = argv[1];
	len = strlen(input_str);

	key[0] = chars[(len ^ 0x3B) & 0x3F];
	for (i = 0, j = 0; i < len; i++)
		j += input_str[i];
	key[1] = chars[(j ^ 0x4F) & 0x3F];
	for (i = 0, j = 1; i < len; i++)
		j *= input_str[i];
	key[2] = chars[(j ^ 0x55) & 0x3F];
	for (i = 0, j = input_str[0]; i < len; i++)
		if ((char)j <= input_str[i])
			j = input_str[i];
	srand(j ^ 0xE);
	key[3] = chars[rand() & 0x3F];
	for (i = 0, j = 0; i < len; i++)
		j += input_str[i] * input_str[i];
	key[4] = chars[(j ^ 0xEF) & 0x3F];
	for (i = 0, j = 0; (char)i < input_str[0]; i++)
		j = rand();
	key[5] = chars[(j ^ 0xE5) & 0x3F];
	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}
