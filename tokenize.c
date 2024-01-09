#include "main.h"

/**
 * token_count - function that returns the number of token counted
 * @input: address of a string pointer
 * @delimeter: the charcter that separates the strings
 *
 * Return: the number of tokens found
 */
size_t token_count(char *input, char *delimeter)
{
	size_t token_count = 0;
	char *line;

	line = NULL;
	if (input == NULL)
		return (0);

	line = strtok(input, delimeter);
	while (line != NULL)
	{
		token_count++;
		line = strtok(NULL, delimeter);
	}

	return (token_count);
}

/**
 * tokenize - function that separates a string using a delemiter
 * @input: address of a string pointer
 * @delimiter: the character that separates the string
 *
 * Return: the pointer to the separated strings
 */
char **tokenize(char *input, char *delimiter)
{
	char **tokens, *input_copy, *token;
	size_t token_cnt, cnt;

	if (input == NULL)
		return (NULL);

	input_copy = malloc((strlen(input) + 1) * sizeof(char));
	if (input_copy == NULL)
	{
		perror("Error: input_copy malloc failed");
		return (NULL);
	}
	strcpy(input_copy, input);
	token_cnt = token_count(input_copy, delimiter);
	strcpy(input_copy, input);
	tokens = malloc((token_cnt + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Error: tokens malloc failed");
		free(input_copy);
		return (NULL);
	}
	token = strtok(input_copy, delimiter);
	for (cnt = 0; cnt < token_cnt; cnt++)
	{
		tokens[cnt] = malloc((strlen(token) + 1) * sizeof(char));
		if (tokens[cnt] == NULL)
		{
			perror("Error: token malloc failed");
			free(tokens);
			free(input_copy);
			return (NULL);
		}
		strcpy(tokens[cnt], token);
		token = strtok(NULL, delimiter);
	}
	tokens[token_cnt] = NULL;
	free(input_copy);
	return (tokens);
}

