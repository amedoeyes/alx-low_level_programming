/**
 * print_name - print name
 *
 * @name: name
 * @f: callback
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
