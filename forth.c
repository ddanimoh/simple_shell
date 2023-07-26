#include "main.h"
/**
 * handle_builtin_commands - compriment
 * @args: agai
 * Return: kw
 */
int handle_builtin_commands(char **args)
{
	char *home;

	if (strcmp(args[0], "exit") == 0)
	{
		free_memory(args);
		return (0);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			home = getenv("HOME");
			chdir(home);
		}
		else
		{
			if (chdir(args[1]) != 0)
				perror("cd error");
		}
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1);
	}
	return (-1);
}
/**
 * free_memory - mem free
 * @args: gain
 * Return: no re
 */
void free_memory(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
