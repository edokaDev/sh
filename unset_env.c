#include "main.h"

/**
 * _unsetenv - unsets an environmental variable
 *
 * @cmd: array of commands from user input
 * Return: (0) success
 */

int _unsetenv(char **cmd)
{
	if (cmd[1] == NULL)
		perror(cmd[0]);
	if (unsetenv(cmd[1]) != 0)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}
