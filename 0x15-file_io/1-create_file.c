#include "main.h"

/**
 * create_file - creates a file with given conten
 *
 * @filename: file to create
 * @text_content: content of file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;

	if (!filename)
		return (-1);

	if (!text_content)
		text_content = "";

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (write(fd, text_content, strlen(text_content)) == -1)
		return (-1);

	return (1);
}
