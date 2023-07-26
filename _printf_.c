#include "main.h"
#include <unistd.h>

/**
*_print_char - Helper function to print a character.
*
*@c: character to be printed
*Return: inputted Character
*/
static int _print_char(char c)
{
	return (write(1, &c, 1));
}

/**
* _print_integer - Helper function to print an integer.
*@num: number to be printed
*Return: inputted interger
*/
static int _print_integer(int num)
{
	char buffer[20];
	int i = 0;

	if (num == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = -num;
		}

		while (num > 0)
		{
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}

	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}

	return (i);
}

/**
*_printf - Produces output according to a format.
*@format : output format
*Return: printed character
*/
int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			chara_print += _print_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				chara_print += _print_char(*format);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list, int);

				chara_print += _print_integer(num);

			}
		}

		format++;
	}

	va_end(list);

	return (chara_print);
}

