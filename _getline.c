#include "main.h"

/**
 * _getline - reads user input into the buffer
 * @buffer: stores the user input
 *
 * Return: the number of bytes read.
*/
int _getline(char *buffer)
{
	static int bytes_read, current;
	int size;
	static char buf[BUFFER_SIZE];

	if (current >= bytes_read)
	{
		bytes_read = read(STDIN_FILENO, buf, BUFFER_SIZE - 1);
		if (bytes_read <= 0)
		{
			return (-1);
		}
		current = 0;
	}
	for (size = 0;
			buf[current + size] != '\n' && buf[current + size] != '\0'; size++)
	{

	}
	buffer[0] = 0;
	strncat(buffer, buf + current, size);
	current = current + size + 1;

	return (size + 1);
}
