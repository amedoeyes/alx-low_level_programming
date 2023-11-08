/**
 * int_index - search for an integer in an integer array
 *
 * @array: array
 * @size: size of array
 * @cmp: comparison callback
 *
 * Return: index
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	int index = -1;

	if (!array || !cmp)
		return (index);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (index);
}
