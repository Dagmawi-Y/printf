#include "main.h"
#include <stdarg.h>

/**
 * handle_specifier - Handles the switch-case logic for each specifier.
 * @specifier: The specifier character.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int handle_specifier(char specifier, va_list args)
{
    switch (specifier)
    {
        case 'c':
            return print_char(args);
        case 's':
            return print_string(args);
        case '%':
            return print_percent(args);
        case 'd':
        case 'i':
            return print_integer(args);
        case 'b':
            return print_binary(args);
        case 'u':
            return print_unsigned(args);
        case 'o':
            return print_octal(args);
        case 'x':
            return print_hex(args);
        case 'X':
            return print_hex_upper(args);
        default:
            return _putchar('%') + _putchar(specifier);
    }
}
