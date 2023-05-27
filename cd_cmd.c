#include "main.h"

/**
 * cd_cmd - changes directory
 * @cmd: the directory to change to
 * Return: 0 on success
 */

int cd_cmd(char **cmd)
{
	const char *home_dir;
	char *buffer, *buffer2;
	char *buf, *current, *oldpwd;
	size_t size = 100;

	if (cmd[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
			perror("cd");
	}
	buffer = malloc(sizeof(char) * size);
	if (!buffer)
		return (-1);
	current = getcwd(buffer, size);

	if (_strcmp(cmd[1], "-") == 0)
	{
		oldpwd = getenv("OLDPWD");
		setenv("OLDPWD", current, 1);
		setenv("PWD", oldpwd, 1);
		write(STDOUT_FILENO, oldpwd, _strlen(oldpwd));
		write(STDOUT_FILENO, "\n", 1);
		free(current);
		free(buffer);
		free(oldpwd);
		return (0);
	}

	if (chdir(cmd[1]) != 0)
	{
		free(current);
		free(buffer);
		perror("cd");
		return (1);
	}
	setenv("OLDPWD", current, 1);
	buffer2 = malloc(sizeof(char) * size);
	if (!buffer)
		return (-1);
	buf =  getcwd(buffer, size);
	setenv("PWD", buf, 1);

	free(buffer), free(current), free(buf);
	free(buffer2);
	return (0);
}

