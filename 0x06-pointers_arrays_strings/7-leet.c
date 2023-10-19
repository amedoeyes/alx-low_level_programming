/**
 * leet - encodes a string into 1337
 *
 * @str: string
 *
 * Return: pointer to the encoded string
 */

char *leet(char *str)
{
	int i, j;
	char *a = "aAeEoOtTlL";
	char *b = "4433007711";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; a[j]; j++)
		{
			if (str[i] == a[j])
			{
				str[i] = b[j];
			}
		}
	}

	return (str);
}
