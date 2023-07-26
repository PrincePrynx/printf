#include "main.h"

/**
 * print_char - prints a char
 * @list: lists arguments passed
 * Return: number of characters printed
 */

int print_char(va_list list)
{
	_putchar_(va_arg(list, int));
	return (1);
}

/**
 * print_string - prints a string
 * @list: lists arguments passed
 * Return: final output
 */

int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar_(str[i]);
	return (i);
}

/**
 * print_percent - prints the percent sign
 * @list: lists arguments passed
 * Return: output
 */

int print_percent(__attribute__((unused))va_list list)
{
	_putchar_('%');
	return (1);
}

/**
 * print_integer - prints an integer(%d, %i)
 * @list: lists arguments passed
 * Return: output
 */

int print_integer(va_list list)
{
	int d;

	d = print_number(list);
	return (d);
}

/**
 * unsigned_integer - Entry point
 * @list: lists arguments passed
 * Return: the output
 */

int unsigned_integer(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (print_unsgined_number(num));
	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}
