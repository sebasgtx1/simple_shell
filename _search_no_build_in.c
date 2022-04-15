#include "shell.h"
/**
 * search_no_build_in - funtions that search if the argument is
 * a not build in funtion
 * @args: the argument list
 * Return: 1 if the funtion finds the command or 0 if fails
 */

int search_no_build_in(char **args)
{
	int j = 0;
	char **env = environ, *copy, *token;
	char *command = calloc(strlen(args[0]) + 3, 1);
	char *dest = NULL;
	size_t command_size;
	struct stat sb;

	for (; env[j]; j++)
	{
		if ((strncmp("PATH", env[j], 4)) == 0)
		{
			break;
		}
	}
	copy = malloc(strlen(env[j]) + 1);
	strcpy(copy, env[j]);
	strcat(command, "/");
	strcat(command, args[0]);
	token = _strtok(copy, DELIMITERS);
	command_size = strlen(command) + 1;

	while ((token = _strtok(NULL, DELIMITERS)))
	{
		dest = calloc(strlen(token) + 1 + command_size, 1);
		strcat(dest, token);
		strcat(dest, command);
		if (stat(dest, &sb) != -1)
		{
			args[0] = malloc(strlen(dest) + 1);
			args[0] = strcpy(args[0], dest);
			free(dest);
			free(command);
			free(copy);
			return (1);
		}
		free(dest);
	}
	free(command);
	free(copy);
	return (0);
}