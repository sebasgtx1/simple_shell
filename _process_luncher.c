#include "shell.h"
/**
 * _process_launcher - funtion that excecute a command
 * @args: argument list
 * @fail: exit status
 * Return: Always 1, for re-print the prompt after the
 * command excecution
 */
int _process_launcher(char **args, int *fail)
{
	pid_t pid, wait_pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, NULL);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			wait_pid = waitpid(pid, &status, WUNTRACED | WCONTINUED);
			if (wait_pid == -1)
			{
				exit(*fail);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (WIFEXITED(status))
		{
			*fail = WEXITSTATUS(status);
		}
	}
	return (1);
}
