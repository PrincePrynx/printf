#include "main.h"

/**
 * _putchar_ - writes the character c to stdout
 * @c: The character to print
 *
 * Return: 1 (Success) and -1 prints (Error)
 */
int _putchar_(char c)
{
	return (write(1, &c, 1));
}
