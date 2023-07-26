#include "main.h"
/**
 * execute_command - w
 * @args: args
 * Return: dnt kw
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (1);

	status = handle_builtin_commands(args);
	if (status != -1)
		return (status);

	pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		return (1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp error");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	return (1);
}
