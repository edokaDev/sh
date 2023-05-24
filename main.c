#include "main.h"

/**
 * main -shell
 *
 * Return: 0 Success
 */

int main(void)
{
	char *input = NULL, *prompt = "$ ", *cmd[50];
	size_t len = 0;
	ssize_t nread = 0;

	do {
		write(STDOUT_FILENO, prompt, strlen(prompt));
		nread = getline(&input, &len, stdin);
		if (!nread)
			return (-1);
		if (input[0] == '\n')
		{
			free(input);
			continue;
		}
		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(input, "env") == 0)
		{
			print_env(env);
			continue;
		}
		free(input);
		input = NULL;
		len = 0;
	} while (1);

	return (0);
}

