#include "main.h"
#include "stdio.h"

/**
 * create_path - function that creates path
 * @file_path: the pointer address that will hold the path
 * @array_tokens: a double pointer argument
 * @filename: the command that it's path will be created
 * @tok_cnt: the count of the token
 * Return:void
 */
void create_path(char **file_path, char **array_tokens,
		char *filename, int tok_cnt)
{
	int len;

	len = strlen(filename) + strlen(array_tokens[tok_cnt]) + 2;
	*file_path = malloc(sizeof(char) * len);
	if (*file_path == NULL)
	{
		perror("Error");
		return;
	}
	strcpy(*file_path, array_tokens[tok_cnt]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * path_valid - function that checks if the path is valid
 * @command: the argument that is to be checked
 *
 * Return: (1) on sucess and (0) otherwise
 */
int path_valid(char *command)
{
	if (!command)
		return (0);

	if (strncmp(command, "../", strlen("../")) == 0)
		return (1);

	if (strncmp(command, "./", strlen("./")) == 0)
		return (1);

	if (strncmp(command, "/", strlen("/")) == 0)
		return (1);

	return (0);
}

/**
 * found_path - a function that finds path and return the path found
 * @command: the command passed as argument
 *
 * Return: filepath on success and NULL on failure
 */
char *found_path(char *command)
{
	char *path_str, *delimeter = ":";
	char **tokens, *filepath, *path_str_copy;
	int path_exist, token_cnt;
	struct stat buf;

	path_str = getenv("PATH");
	if (path_str != NULL)
	{
		path_str_copy = strdup(path_str);
		if (path_str_copy)
		{
		tokens = tokenize(path_str_copy, delimeter);
		if (tokens != NULL)
		{
			for (token_cnt = 0; tokens[token_cnt]; token_cnt++)
			{
				create_path(&filepath, tokens, command, token_cnt);

				if (stat(filepath, &buf) == 0)
				{
					return (filepath);
				}
				free(filepath);
			}
			/*free_path(&path_str, tokens);*/
		}
		else
			free(path_str);
		}
	}
	path_exist = stat(command, &buf);
	if (path_exist == 0 && path_valid(command))
		return (strdup(command));

	return (NULL);
}

