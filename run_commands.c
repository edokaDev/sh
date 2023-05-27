#include "main.h"

/**
 * run_commands - run the commands
 * @input: input command args
 * @env: environs
 * @argv: args list
 * @not_pipe: piped or not
 *
 * Return: nothing
*/
int run_commands(char *input, char **env, char **argv, int not_pipe)
{
	char *cmd[50], *path;
	int exec_status;

	(void) not_pipe;
	if (input[0] == '\0')
	{
		free(input);
		return (0);
	}
	parse_input(input, cmd);
	if (strcmp(cmd[0], "env") == 0)
	{
		free(input);
		print_env(env);
		return (0);
	}
	if (strcmp(cmd[0], "cd") == 0)
	{
		cd_cmd(cmd);
		free(input);
		free_input(cmd);
		return (0);
	}
	if (strcmp(cmd[0], "setenv") == 0)
	{
		free(input);
		_setenv(cmd);
		return (0);
	}
	if (strcmp(cmd[0], "unsetenv") == 0)
	{
		free(input);
		_unsetenv(cmd);
		return (0);
	}
	if (strcmp(cmd[0], "exit") == 0)
		handle_exit(input, cmd, argv);
	path = get_path(cmd[0], env);
	if (path == NULL)
	{
		perror("path not found");
		return (0);
	}
	free(cmd[0]);
	cmd[0] = path;
	exec_status = _execve(path, cmd, env, argv, input);
	return (exec_status);
}
