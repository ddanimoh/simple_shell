#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_ARG_LEN 256

extern char **environ;

void display_prompt();
char **parse_input(char *input);
int execute_command(char **args);
int handle_builtin_commands(char **args);
void free_memory(char **args);

#endif
