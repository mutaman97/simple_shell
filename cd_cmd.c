#include "main.h"

/**
 * chdir_cmd - this function implements the CD command
 * @array_tokens: the array argument
 *
 * Return: (0) on success and (-1) on failure
 */
int chdir_cmd(char **array_tokens)
{
	int cnt;
	char buf[BUFF_SIZE];


	if (array_tokens[1] == NULL)
	{
		cnt = chdir(getenv("HOME"));
	}

	else if (strcmp(array_tokens[1], "-") == 0)
	{
		cnt = chdir(getenv("OLDPWD"));
		getcwd(buf, BUFF_SIZE);
		write(1, buf, strlen(buf));
		write(1, "\n", 1);
	}

	else
	{
		cnt = chdir(array_tokens[1]);
	}

	if (cnt == -1)
	{
		perror("Error");
	}
	else if (cnt != -1)
	{
		getcwd(buf, BUFF_SIZE);
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", buf, 1);
	}
	return (0);
}

