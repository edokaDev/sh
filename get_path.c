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
	char *curr_path = NULL, *paths = NULL, *curr_copy = NULL;

	if (access(input, F_OK) == 0)
		return (strdup(input));
	while (envp[i] != NULL)
	{
		if (strncmp("PATH=", envp[i], 5) == 0)
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
				}
				strcpy(curr_copy, curr_path);
				strcat(curr_copy, "/");
				strcat(curr_copy, input);
				if (access(curr_copy, F_OK) == 0)
				{
					free(paths);
					return (curr_copy);
				}
				free(curr_copy);
				curr_path = strtok(NULL, ":");
			}
			break;
		}
		i++;
	}
	if (paths != NULL)
		free(paths);
	return (NULL);
}
