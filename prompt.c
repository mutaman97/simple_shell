#include "main.h"

/**
 * prompt - function that prints the prompt message
 *
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, ":) ", strlen(":) "));
	}
}
