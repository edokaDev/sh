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
	char *input = NULL, *prompt = "$ ", *cmd[50], *path, buffer[BUFFER_SIZE];
	int not_pipe, nread = 1, exec_status;

	while (nread != 0)
	{
		not_pipe = isatty(STDIN_FILENO);
		if (not_pipe == 1)
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		nread = _getline(buffer);
		if (nread == 0)
			break;
		input = malloc(sizeof(char) * nread);
		if (input == NULL)
		{
			perror(argv[0]);
			return (1);
		} _strcpy(input, buffer);
		if (input[0] == '\0')
		{
			free(input);
			continue;
		}
		if (_strcmp(input, "env") == 0)
		{
			free(input);
			print_env(env);
			continue;
		} parse_input(input, cmd);
		if (_strcmp(cmd[0], "cd") == 0)
		{
			cd_cmd(cmd);
			free(input);
			free_input(cmd);
			continue;
		}
		if (_strcmp(cmd[0], "exit") == 0)
			handle_exit(input, cmd, argv);
		path = get_path(cmd[0], env);
		if (path[0] == '/')
		{
			exec_status = _execve(path, cmd, env, argv, input, not_pipe);
			if (exec_status != 0) /* error in command, usually invalid args */
				perror(argv[0]);
		} else /*command not found*/
			free(path), free(input), free_input(cmd), perror(argv[0]);
		input = NULL;
	}
	if (input != NULL)
		free(input);
	if (not_pipe == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
