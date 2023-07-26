#include "main.h"
/**
 * main - main
 * Return: 0
 */
int main(void)
{
	size_t bufsize;
	char *input;
	char **args;
	int status;

	while (1)
	{
		display_prompt();
		input = NULL;
		bufsize = 0;

		getline(&input, &bufsize, stdin);

		if (input == NULL)
		{
			putchar('\n');
			break;
		}

		args = parse_input(input);
		if (args == NULL)
			continue;

		status = execute_command(args);

		free(input);
		free_memory(args);

		if (status == 0)
			break;
	}

	return (0);
}
