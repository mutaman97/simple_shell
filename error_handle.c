#include "main.h"

/**
 * error_hand - composes error message
 * @token: double pointer
 * @argv: the array of character passed to the command line
 * @len: line count of the shell program
 * Return: (0)
 */
int error_hand(char **token, char **argv, int len)
{
	char *message, *error, process[20];
	int cnt;

	message = "not found";
	_itoa(len, process, sizeof(process));
	cnt = len + strlen(message) + 5 + strlen(argv[0]);
	error = malloc(sizeof(char) * cnt);

	strcpy(error, argv[0]);
	strcat(error, ": ");
	if (token[0] != NULL)
	{
		strcat(error, process);
		strcat(error, ": ");
		strcat(error, token[0]);
		strcat(error, ": ");
		strcat(error, message);
	}
	else
		strcat(error, message);


	strcat(error, "\0");
	write(1, error, strlen(error));
	write(1, "\n", 1);

	return (0);
}
