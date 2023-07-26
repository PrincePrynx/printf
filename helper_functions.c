#include "main.h"
#include <stdio.h>

/**
 * rev_string - reverses a string
 * @s: string to reverse
 * Return: pointer to a char
 */

char *rev_string(char *s)
{
	int a;
	int b;
	char new;
	char *dest;

	for (a = 0; s[a] != '\0'; a++)
	{}

	dest = malloc(sizeof(char) * a + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, a);
	for (b = 0; b < a; b++, a--)
	{
		new = dest[a - 1];
		dest[a - 1] = dest[b];
		dest[b] = new;
	}
	return (dest);
}

/**
 * write_base - prints chars to standard output
 * @str: is the string
 */
void write_base(char *str)
{
	int m;

	for (m = 0; str[m] != '\0'; m++)
		_putchar_(str[m]);
}

/**
 * base_len - calculates the length of an octal number
 * @num: input value
 * @base: input value
 * Return: an integer
 */

unsigned int base_len(unsigned int num, int base)
{
	unsigned int y = 0;

	for (; num > 0; y++)
	{
		num = num / base;
	}
	return (y);
}


/**
 * _memcpy - function that copies memory area
 * @dest: stored memory area
 * @src: copied memory area
 * @n: bytes number
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int c = 0;

	for (; c < n; ++c)
	{
		*(dest + c) = *(src + c);
	}
	return (dest);
}
