#include "main.h"
#include <unistd.h>

/**
* _printf - Produces output according to a format.
* @format: The format string containing directives.
*
* Return: The number of characters printed
*/

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int chars_written = 0;

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{

write(STDOUT_FILENO, &c, 1);
chars_written++;
}
break;
case 's':
{

char *str = va_arg(args, char *);
int str_length = 0;
while (str[str_length] != '\0')
{
str_length++;
}
write(STDOUT_FILENO, str, str_length);
chars_written += str_length;
}
break;
case '%':
{

write(STDOUT_FILENO, "%", 1);
chars_written++;
}
break;
default:
{

write(STDOUT_FILENO, "%", 1);
write(STDOUT_FILENO, format, 1);
chars_written += 2;
}
break;
}
}
else
{

write(STDOUT_FILENO, format, 1);
chars_written++;
}
format++;
}

va_end(args);

return (chars_written);
}
