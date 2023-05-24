#include "main.h"

/**
 * free_input - free the input command args
 * @cmd: array of command args
 *
 * Return: nothing
*/
void free_input(char **cmd)
{
	int i = 0;

	while (cmd[i] != NULL)
		free(cmd[i++]);
}
