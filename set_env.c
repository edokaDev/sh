#include "main.h"

/**
 * _setenv - sets the environment variables
 * @cmd: name of the environment variable to set
 * an existing value if it already exist.
 * Return: 0 on Success
 */
int _setenv(char **cmd)
{
	if (cmd[1] == NULL || cmd[2] == NULL)
		perror(cmd[0]);

	if (setenv(cmd[1], cmd[2], 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}
