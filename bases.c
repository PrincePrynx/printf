#include "main.h"
#include <stdio.h>

int hex_check(int num, char x);

/**
 * print_binary - Converts a number of base 10 to binary
 * @list: List of args
 * Return: output
 */
int print_binary(va_list list)
{	int m, n;
	char *str;
	char *rev_str;
	unsigned int num;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar_(48));
	if (num < 1)
		return (-1);
	n = base_len(num, 2);
	str = malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (-1);

	for (m = 0; num > 0; m++)
	{
		if (num % 2 == 0)
			str[m] = 48;
		else
			str[m] = '1';
		num = num / 2;
	}
	str[m] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (n);
}

/**
 * print_octal - converts a number the octal base
 * @list: List of all the arguments passed
 * Return: N/A
 */

int print_octal(va_list list)
{
	int c;
	char *obase;
	char *rev_str;
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar_('0'));
	if (num < 1)
		return (-1);
	c = base_len(num, 8);

	obase = malloc(sizeof(char) * c + 1);
	if (obase == NULL)
		return (-1);
	for (c = 0; num > 0; c++)
	{
		obase[c] = (num % 8) + 48;
		num = num / 8;
	}
	obase[c] = '\0';
	rev_str = rev_string(obase);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(obase);
	free(rev_str);
	return (c);
}

/**
 * print_hexlower - Prints a decimal number of base 16 in lowercase
 * @list: List of the arguments passed
 * Return: output
 */

int print_hexlower(va_list list)
{
	unsigned int num;
	int lowx;
	int b;
	char *hex;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar_(48));
	if (num < 1)
		return (-1);
	lowx = base_len(num, 16);
	hex = malloc(sizeof(char) * lowx + 1);
	if (hex == NULL)
		return (-1);
	for (lowx = 0; num > 0; lowx++)
	{
		b = num % 16;
		if (b > 9)
		{
			b = hex_check(b, 'x');
			hex[lowx] = b;
		}
		else
			hex[lowx] = b + 48;
		num = num / 16;
	}
	hex[lowx] = '\0';
	rev_hex = rev_string(hex);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex);
	free(rev_hex);
	return (lowx);
}

/**
 * print_heXupper - Prints a decimal number of base 16 in Uppercase
 * @list: List of the arguments passed
 * Return: Number of characters printed
 */

int print_heXupper(va_list list)
{
	unsigned int num;
	int upX;
	int b;
	char *hex;
	char *rev_hex;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar_('0'));
	if (num < 1)
		return (-1);
	upX = base_len(num, 16);
	hex = malloc(sizeof(char) * upX + 1);
	if (hex == NULL)
		return (-1);
	for (upX = 0; num > 0; upX++)
	{
		b = num % 16;
		if (b > 9)
		{
			b = hex_check(b, 'X');
			hex[upX] = b;
		}
		else
			hex[upX] = b + 48;
		num = num / 16;
	}
	hex[upX] = '\0';
	rev_hex = rev_string(hex);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex);
	free(rev_hex);
	return (upX);
}



/**
 * hex_check - prints lower or upper hexa
 * @num: number to convert
 * @x:input value
 * Return: the ascii value
 */

int hex_check(int num, char x)
{
	char *hexlower = "abcdef";
	char *heXupper = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hexlower[num]);
	else
		return (heXupper[num]);
	return (0);
}
