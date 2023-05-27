#include "main.h"
#include <signal.h>

/**
 * handle_exit - handles when exit is typed to the shell
 * @input: user input
 * @cmd: exit status
 * @argv: argument list to main
 *
 * Return: nothing.
*/
void handle_exit(char *input, char **cmd, char *argv[])
{
	int n;


	char *buffer;
	char *err = ": 1: exit: Illegal number: ";

	free(input);
	if (cmd[1] != NULL)
	{
		n = atoi(cmd[1]);

		buffer = malloc(sizeof(char) *
			(_strlen(argv[0]) + _strlen(err) + _strlen(cmd[1]) + 1));

		if (n < 0 || (n < 10 && _strlen(cmd[1]) > 1))
		{
			_strcat(_strcat(_strcat(buffer, argv[0]), err), cmd[1]);
			write(STDERR_FILENO, buffer, _strlen(buffer));
			write(STDERR_FILENO, "\n", 1);
			free(buffer);
			exit(2);
		}
		free_input(cmd);
		free(buffer);
		exit(n);
	}
	free_input(cmd);
	exit(EXIT_SUCCESS);

}
