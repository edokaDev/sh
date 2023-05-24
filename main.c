#include "main.h"

/**
 * main - shell
 * @argc: argument count
 * @argv: array of arguments
 * @env: array of environs variable passed to the functino
 *
 * Return: on success 0, on failure... non-zero.
*/
int main(int __attribute__ ((unused)) argc, char *argv[], char *env[])
{
	struct stat statbuf;
	char *input = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	char *prompt = "#cisfun$ ";
	char *cmd[] = {NULL};
	pid_t child;
	int status;

	while (nread != -1)
	{
		printf("%s", prompt);
		nread = getline(&input, &len, stdin);
		input[strcspn(input, "\n")] = '\0';
		/* this is to get rid of the \n at end of input*/
		if (*input == '\0')
			continue;
		/* handle regular input vs pipe */
		fstat(STDIN_FILENO, &statbuf);
		if (S_ISFIFO(statbuf.st_mode))
			return (execve(input, cmd, env));
		child = fork(); /* copy of current process, return 0 or -1 */
		if (child == -1)
		{
			fprintf(stderr, "Error creating child process");
			return (1);
		} else if (child == 0)
		{
			/* on success, execve returns 0, -1 on failure */
			return (execve(input, cmd, env));
		}
		/* parent process waits on child*/
		wait(&status);
		if (status != 0)
			printf("%s: No such file or directory\n", argv[0]);
		free(input);
		input = NULL;
	}
	printf("\n");
	return (0);
}
