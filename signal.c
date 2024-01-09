#include "main.h"

/**
 * handle_signal - function that handles ^C exit
 * @signal: an integer argument
 *
 * Return: void
 */
void handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}

