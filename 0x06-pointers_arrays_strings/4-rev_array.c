/**
 * reverse_array - reverses array
 * @a: array
 * @n: number of elements
 */

void reverse_array(int *a, int n)
{
	int i;
	int j = n - 1;
	int temp;

	for (i = 0; i < j; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
