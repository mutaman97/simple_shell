#include "main.h"

/**
 * my_getline - a function that gets the number of char read from the user
 * @input: the address of pointer to the string
 * @num_alloced: the count process
 * Return: number of character read
 */
ssize_t my_getline(char **input, size_t *num_alloced)
{
	/*char *string, **line;*/
	ssize_t num_char_read;

	if (!(input))
	{
		exit(EXIT_CODE);
	}
	if (!num_alloced)
	{
		exit(EXIT_CODE);
	}

	num_char_read = getline(input, num_alloced, stdin);
	if (num_char_read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "/n", 1);

		exit(EXIT_CODE);
	}

	return (num_char_read);
}

