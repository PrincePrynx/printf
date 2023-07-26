#include "main.h"

/**
 * print_number - prints a number
 * @args: arguments variable
 * Return: number of arguments printed
 */

int print_number(va_list args)
{
	int n;
	int a = 1;
	int b = 0;
	unsigned int num;

	n  = va_arg(args, int);
	if (n < 0)
	{
		b += _putchar_('-');
		num = n * -1;
	}
	else
		num = n;
	for (; num / a > 9; )
		a *= 10;

	for (; a != 0; )
	{
		b += _putchar_('0' + num / a);
		num %= a;
		a /= 10;
	}
	return (b);
}

/**
 * print_unsgined_number - prints the unsigned number
 * @n: is the integer
 * Return: total printed num
 */

int print_unsgined_number(unsigned int n)
{
	int a = 1;
	int b = 0;
	unsigned int num;

	num = n;

	for (; num / a > 9; )
		a *= 10;

	for (; a != 0; )
	{
		b += _putchar_('0' + num / a);
		num %= a;
		a /= 10;
	}
	return (b);
}
