#include "main.h"
/**
 * _itoa - a function that convert a string to a number
 * @n: the lemgth of the string
 * @buffer: the buffer to hold the string
 * @buflen: the size of the buffer
 * Return: void
 */

void _itoa(int n, char buffer[], int buflen)
{
	snprintf(buffer, buflen, "%d", n);
}
