#include "main.h"
/**
 * main - main code
 * @argc: number of argument passed
 * @argv: the pointer to the strings of the argument passed
 * @envp: argument 3
 * Return: 0
 */
int main(__attribute((unused)) int argc,
		__attribute((unused)) char **argv,
		__attribute((unused)) char **envp)
{
	char *input, **token, *delimeter, *path;
	size_t num_alloced = 0;
	int cmd_line, status = 0;

	cmd_line = 0;
	delimeter = "\n ";
	signal(SIGINT, handle_signal);
	while (1)
	{
		prompt();
		cmd_line++;
		my_getline(&input, &num_alloced, status);
		/*len = strlen(input);*/
		if (input[0] == ' ' || strlen(input) == 1)
			continue;
		token = tokenize(input, delimeter);
		if (!token)
			status = 0;
		else
		{
			if (check_builtin(token) == 0)
			{
				if (is_builtin(token) < 0)
					free_main(token);
					exit(status);
			}
			else
			{
				path = found_path(token[0]);
				if (path != NULL)
					status = execute(path, token);
				else
					status = error_hand(token, argv, cmd_line);
			}
		}
	cmd_line = 0;
	free(input);
	input = NULL;
	}
	return (0);
}
