#include "main.h"

/**
 * parse - prints a formatted string
 * @format: a string wth a set of characters
 * @f_list: contains the varying functions
 * @arg_list: list containing all the arguments
 * Return: total count of the characters printed
 */

int parse(const char *format, sample_t f_list[], va_list arg_list)
{
	int i, m, z, ch_print;

	ch_print = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') /** Checks for format specifiers **/
		{
			for (m = 0; f_list[m].op != NULL; m++)
			{
				if (format[i + 1] == f_list[m].op[0])
				{
					z = f_list[m].f(arg_list);
					if (z == -1)
						return (-1);
					ch_print += z;
					break;
				}
			}
			if (f_list[m].op == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar_(format[i]);
					_putchar_(format[i + 1]);
					ch_print = ch_print + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar_(format[i]);
			ch_print++;
		}
	}
	return (ch_print);
}
