#include "main.h"

/**
 * print_env - print out the environmental variables passed to the function
 * @envp: pointer to the array of environmental variables
 *
 * Return: nothing.
 */

void print_env(char *envp[])
{
	int i = 0;

	while (envp[i] != NULL)
	{
		write(STDOUT_FILENO, envp[i], strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
