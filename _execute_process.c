#include "shell.h"
/**
 * _execute - funtion that check if the input is
 * a command (build in, non build in, a path of a
 * non build in or not a command at all)
 * @args: the argument list
 * Return: always 1 (exception: the excecution of the
 * exit build in)
 */

int _execute(char **args)
{
	int (*func)(char **);
	struct stat sb;

	if (!args[0])
		return (1);

	if (stat(args[0], &sb) != -1)
		return (_process_launcher(args));
	func = get_build_in(args[0]);
	if (!func)
	{
		if (search_no_build_in(args))
		{
			_process_launcher(args);
			free(args[0]);
			return (1);
		}
		else
		{
			int i = 0;
			char i_char, *args_0 = "/hsh", *args_1 = args[0];

			for (; args[i]; i++)
				;
			i_char = i + '0';
			write(STDERR_FILENO, args_0, _strlen(args_0));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, &i_char, 1);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, args_1, _strlen(args_1));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "not found\n", 10);
			return (1);
		}
	}
	return (func(args));
}
