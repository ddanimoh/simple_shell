#include "main.h"
/**
 * display_prompt - desc
 * Return: void fun
 */
void display_prompt(void)
{
	printf("simple_shell$ ");
}
/**
 * parse_input - input
 * @input: input
 * Return: dnt knw
 */
char **parse_input(char *input)
{
	char *token;
	int i = 0;
	char **args = malloc(MAX_ARGS * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc error");
		return (NULL);
	}

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup error");
			free_memory(args);
			return (NULL);
		}

		token = strtok(NULL, " \t\n");
		i++;
	}
	args[i] = NULL;

	return (args);
}
