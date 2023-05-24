#include "main.h"

/**
 * parse_input - split the input command args and save them to an array
 * @input: input command args
 * @cmd: array to save them to
 *
 * Return: nothing
*/
void parse_input(char *input, char **cmd)
{
	int i = 0;
	char *token;
	char *input_copy = _strdup(input);

	token = strtok(input_copy, " ");

	while (token != NULL)
	{
		cmd[i++] = _strdup(token);
		token = strtok(NULL, " ");
	}
	cmd[i] = NULL;
	free(input_copy);
}

