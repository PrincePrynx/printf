#include "main.h"
#include <unistd.h>

/**
*print_char - Helper function to print a character.
*@chara_print: location of character
*@c: character to be printed
*Return: printed character
*/
static void print_char(char c, int *chara_print)
{
write(1, &c, 1);
(*chara_print)++;
}

/**
*print_integer - Helper function to print an integer.
*@chara_print: location of character
*@num: interger to be printed
*Return: printed interger
*/
static void print_integer(int num, int *chara_print)
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
(*chara_print)++;
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
(*chara_print)++;
}
}

/**
*_printf - Produces output according to a format.
*@format: output
*Return: format of output
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
print_char(*format, &chara_print);
}
else
{
format++;
if (*format == '\0')
break;

if (*format == '%')
{
print_char(*format, &chara_print);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(list, int);
print_integer(num, &chara_print);
}
}

format++;
}

va_end(list);

return (chara_print);
}
