/**
 * get_bit - gets the value of a bit at a given index
 *
 * @n: number
 * @index: index
 *
 * Return: the value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}
