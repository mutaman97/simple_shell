#include "main.h"

/**
 * free_main - function that frees a double pointer
 * @tokens: the double pointer argument
 * Return: void
 */
void free_main(char **tokens)
{
	int cnt;

	for (cnt = 0; tokens[cnt]; cnt++)
	{
		free(tokens[cnt]);
	}
	free(tokens);

}

/**
 * free_path - function that frees a path
 * @path: the path argument
 * @tokens: a double pointer
 * Return: void
 */
void free_path(char **path, char **tokens)
{
	int cnt;

	if (tokens)
	{
		for (cnt = 0; tokens[cnt]; cnt++)
		{
			if (tokens[cnt])
				free(tokens[cnt]);
		}
		free(tokens);
	}
	if (*path)
		free(*path);

}
