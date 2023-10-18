#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int print_pointer(va_list val);
int print_hex_a(unsigned long int num);
int print_hex(va_list val);
int print_es(va_list val);
int print_octal(va_list val);
int print_unsigned(va_list args);
int print_binary(va_list val);
int print_strrev(va_list args);
int print_r13(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int _strlenc(const char *s);
int print_37(void);
int print_charac(va_list val);
int rev_string(char *s);
int print_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
