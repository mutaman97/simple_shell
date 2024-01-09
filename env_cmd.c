#include "main.h"

/**
 * env_cmd - a function that print the enviroment of the current shell
 * @array_tokens: an Unsused parameter
 * Return: the number of character printed.
 */
int env_cmd(__attribute__((unused)) char **array_tokens)
{
	int i, count_words = 0;

	while (*environ != NULL)
	{
		while ((*environ)[i] != '\0')
		{
			if (write(1, &((*environ)[i]), 1) == -1)
			{
				perror("Error");
				exit(EXIT_CODE);
			}
			count_words++;
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		environ++;
	}
	return (count_words);
}
