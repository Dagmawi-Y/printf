#include "main.h"
#include <stdarg.h>

/**
 * print_integer - Prints an integer.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_integer(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    if (num < 0)
    {
        count += _putchar('-');
        num = -num;
    }

    /* Recursively print digits */
    if (num / 10 != 0)
        count += print_integer(args);

    count += _putchar((num % 10) + '0');

    return count;
}
