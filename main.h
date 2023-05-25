#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void parse_input(char *input, char **cmd);
void print_env(char *envp[]);
char *get_path(char *input, char **envp);
void free_input(char **cmd);

/* string functions */
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
unsigned int _strcspn(char *s, char *reject);
char *_strdup(char *str);
int _strlen(char *s);
int _execve(char *path, char **cmd, char **env,
		char **argv, char *input, int not_pipe);


#endif /* MAIN_H */
