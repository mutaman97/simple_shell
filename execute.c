#include "main.h"

/**
 * execute - a function that executes the shell process
 * @command: the command to be executed
 * @array_tokens: the array of string argument
 * Return: (126) on sucess and (-1) on failure
 */
int execute(char *command, char **array_tokens)
{
	pid_t pid;
	int status, exe;

	pid = fork();

	if (pid == -1)
	{
		perror("Error: fork process failed");
		return (-1);
	}

	if (pid == 0)
	{
		exe = (execve(command, array_tokens, environ));
		if (exe == -1)
		{
			perror("Error: exceve failed");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			if (!(isatty(STDIN_FILENO)))
				return (status);

		}
	}
	return (126);
}

