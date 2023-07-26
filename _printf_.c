#include "main.h"


/**
* _printf - writes function that produces output according to a format
* @format: is a character string
* Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int ch_print;
	sample_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hexlower},
		{"X", print_heXupper},
		{"r", print_reverser},
		{"R", rot13},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	ch_print = parse(format, f_list, arg_list);
	va_end(arg_list);
	return (ch_print);
}

