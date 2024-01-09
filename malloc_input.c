#include "main.h"

/**
 * array_maker - function that allocates memory for strings
 * @input: string argument
 * @len: length of the string
 * Return: pointer to the allocated memory and NULL if otherwise
 */
char **array_maker(char **input, size_t len)
{
	char *error_message;

	error_message = "Error: malloc failed";

	input = (char **)malloc(sizeof(char *) * len);
	if (input == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (input);
}

/**
 * char_maker - function that allocates memory for character
 * @input: string argument
 * @len: length of the char
 * Return: the pointer to the memory allocated
 */
char *char_maker(char **input, size_t len)
{
	char *error_message;

	error_message = "Error: malloc failed";

	*input = (char *)malloc(sizeof(char) * len);
	if (*input)
	{
		perror(error_message);
		return (NULL);
	}
	return (*input);
}

