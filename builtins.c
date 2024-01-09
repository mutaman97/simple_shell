#include "main.h"

/**
 * check_builtin - a function that checks for builtin command
 * @array_tokens: a doubled pointer argument
 *
 * Return: (0) on success and (-1) on failure
 */
int check_builtin(char **array_tokens)
{
	const struct funct func[] = {
		{"exit", exit_cmd},
		{"env", env_cmd},
		{"cd", chdir_cmd},
		{NULL, NULL}
	};
	int cnt;

	if (!array_tokens)
		return (-1);

	for (cnt = 0; func[cnt].name; cnt++)
	{
		if (strcmp(array_tokens[0], func[cnt].name) == 0)
		{
			/*free_main(array_tokens);*/
			return (0);
		}
	}
	/*free_main(array_tokens);*/
	return (-1);
}


/**
 * is_builtin - returns the function for the appropiate command
 * @array_tokens: double pointer argument
 *
 * Return: the function on success and (-1) otherwise
 */
int is_builtin(char **array_tokens)
{
	const struct funct func[] = {
		{"exit", exit_cmd},
		{"env", env_cmd},
		{"cd", chdir_cmd},
		{NULL, NULL}
	};
	int cnt;

	if (!array_tokens)
	{
		return (-1);
	}
	if (!(array_tokens[0]))
	{
		return (-1);
	}
	for (cnt = 0; func[cnt].name; cnt++)
	{
		if (strcmp(array_tokens[0], func[cnt].name) == 0)
		{
			return (func[cnt].function(array_tokens));
		}
	}
	return (-1);
}

