#include "main.h"

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
	char *input = NULL, *prompt = "$ ", *cmd[50], *path;
	size_t len = 0;
	ssize_t nread = 0;
	int not_pipe;

	do {
		not_pipe = isatty(STDIN_FILENO);
		if (not_pipe == 1)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		nread = getline(&input, &len, stdin);
		if (!nread || nread == -1)
			break;
		input[_strcspn(input, "\n")] = '\0';
		if (input[0] == '\0')
			continue;
		if (_strcmp(input, "exit") == 0)
			free(input), exit(EXIT_SUCCESS);
		if (_strcmp(input, "env") == 0)
		{
			print_env(env);
			continue;
		} parse_input(input, cmd);
		path = get_path(cmd[0], env);

		if (path[0] == '/')
		{
			_execve(path, cmd, env, argv, input, not_pipe);
		}
		else
		{
			free(path), free(input), free_input(cmd);
			perror(argv[0]);
		}
		input = NULL;

	} while (nread != -1);
	free(input);
	if (not_pipe == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

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
		char **argv, char *input, int not_pipe)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror(argv[0]);
		return (1);
	} else if (child == 0)
		return (execve(path, cmd, env));
	wait(&status);
	if (status != 0)
		perror(argv[0]);
	if (not_pipe == 0)
		return (execve(input, cmd, env));
	free(path), free(input), free_input(cmd);

	return (-1);
}


