#include "main.h"

/**
 * exit_cmd - function that exits a shell process
 * @array_tokens: array of strings argument
 *
 * Return: (0)
 */
int exit_cmd(char **array_tokens)
{
	int status;

	if (array_tokens[1])
	{
		status = atoi(array_tokens[1]);
		exit(status);
	}
	else
		exit(EXIT_CODE);

	return (0);
}

