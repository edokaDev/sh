#include "main.h"
int error_no = 0;
/**
 * main - shell
 * @argc: argument count
 * @argv: array of arguments
 * @env: array of environs variable passed to the function
 *
 * Return: on success 0, on failure... non-zero.
*/
int main(int __attribute__ ((unused)) argc, char *argv[], char *env[])
{
	char *input = NULL, *prompt = "$ ", buffer[BUFFER_SIZE];
	int not_pipe, nread = 1;

	while (nread != 0)
	{
		not_pipe = isatty(STDIN_FILENO);
		if (not_pipe == 1)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		nread = _getline(buffer);
		if (nread < 0)
			break;
		remove_comments(buffer);
		/*strcpy(input, buffer);*/
		input = strip_whitespace(buffer);
		run_commands(input, env, argv);
		input = NULL;
	}
	if (input != NULL)
		free(input);
	if (not_pipe == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
