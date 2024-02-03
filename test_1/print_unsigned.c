#include "main.h"
#include <stdarg.h>

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    if (num == 0)
        return _putchar('0');

    /* Recursively print digits */
    if (num / 10 != 0)
        count += print_unsigned(args);

    count += _putchar((num % 10) + '0');

    return count;
}
