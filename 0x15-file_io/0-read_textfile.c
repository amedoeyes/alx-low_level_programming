#include "main.h"

/**
 * read_textfile - prints text file to standard output
 *
 * @filename: name of the file
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t r;
	int len;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);

	r = read(fd, buf, letters);
	if (r == -1)
		return (0);

	len = write(STDOUT_FILENO, buf, r);
	if (r == -1)
		return (0);

	close(fd);

	return (len);
}
