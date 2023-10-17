#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct format - Match the conversion specifiers for printf
 * @id: The format specifier.
 * @f: Pointer to the corresponding printf function.
 */
typedef struct format
{
    char *id;
    int (*f)(va_list);
} convert_match;

int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_bin(va_list val);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int printf_char(va_list val);
int printf_string(va_list val);
int _printf(const char *format, ...);

#endif
