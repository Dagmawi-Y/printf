#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void itoa_binary(unsigned int num, char *buffer);
int print_hex_oct(const char *format, va_list args);
int print_hex(unsigned int num, int uppercase);

#endif /* MAIN_H */
