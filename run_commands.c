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

	if (input[0] == '\0')
	{
		free(input);
		return (0);
	}
	if (_strcmp(input, "env") == 0)
	{
		free(input);
		print_env(env);
		return (0);
	} parse_input(input, cmd);
	if (_strcmp(cmd[0], "cd") == 0)
	{
		cd_cmd(cmd);
		free(input);
		free_input(cmd);
		return (0);
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
	return (0);
}
