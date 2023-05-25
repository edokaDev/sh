#include "main.h"

/**
 * _getline - reads user input into the buffer
 * @buffer: stores the user input
 *
 * Return: the number of bytes read.
*/
int _getline(char *buffer)
{
	int byte_read;

	byte_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
	if (byte_read == -1)
	{
		perror("read");
		exit(1);
	}
	buffer[byte_read - 1] = '\0';
	return (byte_read);
}
