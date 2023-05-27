#include "main.h"

/**
 * cd_cmd - changes directory
 * @cmd: the directory to change to
 * Return: nothing
 */

void cd_cmd(char **cmd) {
	const char *directory = cmd[1];
    char newDirectory[MAX_PATH_LENGTH];
    char currentDirectory[MAX_PATH_LENGTH];
    char *homeDirectory = getenv("HOME");
    char *previousDirectory = getenv("PWD");
	char *oldPWD = getenv("OLDPWD");
	int prev = 0;

    if (directory == NULL || strcmp(directory, "") == 0) {
        if (homeDirectory == NULL) {
            fprintf(stderr, "cd: No home directory found.\n");
            return;
        }
        strcpy(newDirectory, homeDirectory);
    } else if (strcmp(directory, "-") == 0) {
        if (previousDirectory == NULL) {
            fprintf(stderr, "cd: No previous directory found.\n");
            return;
        }
		prev = 1;
        if (oldPWD == NULL) {
            fprintf(stderr, "cd: No OLDPWD set.\n");
            return;
        }
        strcpy(newDirectory, getenv("OLDPWD"));
    } else {
        strcpy(newDirectory, directory);
    }

    if (chdir(newDirectory) != 0) {
        fprintf(stderr, "cd: Failed to change directory to '%s'\n", newDirectory);
        return;
    }

    /* Update PWD and OLDPWD environment variables */
    if (getcwd(currentDirectory, sizeof(currentDirectory)) != NULL)
	{
        setenv("OLDPWD", previousDirectory, 1);
        setenv("PWD", currentDirectory, 1);
		if (prev == 1)
		{
			write(STDOUT_FILENO, currentDirectory, strlen(currentDirectory));
			write(STDOUT_FILENO, "\n", 1);
		}
    } else
	{
        fprintf(stderr, "cd: Failed to update PWD and OLDPWD environment variables.\n");
    }
}
