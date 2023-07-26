#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
* struct sample - checks for function and operators
*
* @f: is the function
* @op: is the operator
*/
struct sample
{
	char *op;
	int (*f)(va_list);
};
typedef struct sample sample_t;


/** Main functions **/
int _putchar_(char);
int _printf(const char *format, ...);
int parse(const char *format, sample_t f_list[], va_list arg_list);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reverser(va_list arg);
int rot13(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hexlower(va_list list);
int print_heXupper(va_list list);
int print_S(va_list list);
int prints_ptr(va_list list);


/** Extra functions **/
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);

#endif
