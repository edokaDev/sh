#include "main.h"

/**
 * _execve - Executes a command
 * @path: Absolute path of the command
 * @cmd: Command and arguments array
 * @env: Environmental variables array
 * @argv: main function arguments array
 * @input: user input
 * @not_pipe: input mode
 * Return: 0 Success and -1 Failure
 */

int _execve(char *path, char **cmd, char **env,
		char **argv, char *input)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror(argv[0]);
		return (1);
	} else if (child == 0)
	{
		execve(path, cmd, env);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	free(input), free_input(cmd);
	return (0);
}
