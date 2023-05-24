#include "main.h"

/**
 * get_path - function to get the absolute path of the input command.
 * @input: input command
 * @envp: array of environment variables;
 *
 * Return: if found, the absolute path is returned.
 * else, a copy of the input command is return
 * The return variable should be freed in the caller function.
*/
char *get_path(char *input, char **envp)
{
	int i = 0;
	char *curr_path = NULL, *paths = NULL, *curr_copy = NULL, *result = NULL;

	if (input[0] == '/')
		return (strdup(input));
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H' && envp[i][4] == '=')
		{
			paths = strdup(envp[i] + 5);
			curr_path = strtok(paths, ":");
			while (curr_path != NULL)
			{
				curr_copy = malloc(strlen(curr_path) + strlen(input) + 2);
				if (curr_copy == NULL)
				{
					printf("Unable to allocate memory\n");
					free(paths);
					return (strdup(input));
				} strcpy(curr_copy, curr_path), strcat(strcat(curr_copy, "/"), input);
				if (access(curr_copy, F_OK) == 0)
				{
					result = strdup(curr_copy);
					free(paths);
					free(curr_copy);
					return (result);
				} free(paths);
				paths = strdup(curr_copy);
				free(curr_copy);
				curr_path = strtok(NULL, ":");
			} break;
		} i++;
	}
	if (paths != NULL)
	{
		result = strdup(input);
		free(paths);
		return (result);
	} return (strdup(input));
}
