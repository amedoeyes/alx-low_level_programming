#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * error_usage - prints usage error
 */

void error_usage(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * error_read - prints read error
 * @file_name: file name
 */

void error_read(char *file_name)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
	exit(98);
}

/**
 * error_write - prints write error
 * @file_name: file name
 */

void error_write(char *file_name)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
	exit(99);
}

/**
 * error_close - prints close error
 * @file_desc: file descriptor
 */

void error_close(int file_desc)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc);
	exit(100);
}

/**
 * main - copies contents of a file to another file
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success, 97 if invalid number of arguments, 98 if file_from
 * fails, 99 if file_to fails, 100 close fails
 */

int main(int argc, char *argv[])
{
	int file_from;
	int file_to;
	char buffer[BUF_SIZE];
	ssize_t bytes_read;

	if (argc != 3)
		error_usage();

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_read(argv[1]);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
		error_write(argv[2]);

	while ((bytes_read = read(file_from, buffer, BUF_SIZE)) != 0)
	{
		if (bytes_read == -1)
			error_read(argv[1]);

		if (write(file_to, buffer, bytes_read) != bytes_read)
			error_write(argv[2]);
	}

	if (close(file_from) == -1)
		error_close(file_from);

	if (close(file_to) == -1)
		error_close(file_to);

	return (0);
}
