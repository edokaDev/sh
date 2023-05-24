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
struct stat statbuf;

#endif /* MAIN_H */
