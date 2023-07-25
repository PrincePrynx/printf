#include "main.h"
#include <unistd.h>

/**
* _printf - Produces output according to a format.
* @format: The format string containing directives.
*
* Return: The number of characters printed.
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
write(1, format, 1);
chara_print++;
}
else
{
format++;
if (*format == '\0')
break;

if (*format == '%')
{
write(1, format, 1);
chara_print++;
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(list, int);
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
chara_print++;
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
chara_print++;
}
}
}

format++;
}

va_end(list);

return (chara_print);
}
