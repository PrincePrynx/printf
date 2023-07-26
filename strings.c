#include "main.h"

/**
 * print_reverser - reverses a function and prints a string
 * @arg: is the argument
 * Return: output
 */

int print_reverser(va_list arg)
{
	int r;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (r = 0; ptr[r] != '\0'; r++)
		_putchar_(ptr[r]);
	free(ptr);
	return (r);
}

/**
 * rot13 - converts a string to rot13
 * @list: is the string to convert
 * Return: output
 */

int rot13(va_list list)
{
	int a, b;
	char *str;
	char set1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char set2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (a = 0; str[a] != '\0'; a++)
	{
		for (b = 0; b <= 52; b++)
	{
		if (str[a] == set1[b])
		{
			_putchar_(set2[b]);
			break;
		}
	}
		if (b == 53)
			_putchar_(str[a]);
	}
	return (a);
}
