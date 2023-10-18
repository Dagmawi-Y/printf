#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct conversion_specifier - match the conversion specifiers for printf
 * @specifier: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @function: type pointer to function for the conversion specifier
 *
 */

#include <unistd.h>

typedef struct conversion_specifier
{
	char *specifier;
	int (*function)();
} specifier_handler;

int print_pointer(va_list args);
int print_hexadecimal_aux(unsigned long int num);
int print_hexadecimal(va_list args);
int print_exclusive_string(va_list args);
int print_octal(va_list args);
int print_unsigned_decimal(va_list args);
int print_binary(va_list args);
int print_reverse_string(va_list args);
int print_rot13_string(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int string_length(char *s);
int string_copy(char *dest, char *src);
int custom_string_length(const char *s);
int custom_string_length(const char *s);
int print_percent(void);
int print_character(va_list args);
int reverse_string(char *s);
int print_custom_string(va_list args);
int write_character(char c);
int _printf(const char *format, ...);

#endif
