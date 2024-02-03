#include "main.h"
#include <stdarg.h>

/**
 * print_hex - Prints an unsigned integer in hexadecimal.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int hex[32];

    int i;

    /* Convert the integer to hexadecimal representation */
    for (i = 0; i < 32; i++)
    {
        hex[i] = num % 16;
        num /= 16;
    }

    /* Skip leading zeros */
    i = 31;
    while (i >= 0 && hex[i] == 0)
        i--;

    /* If the hexadecimal representation is 0, print a single '0' */
    if (i == -1)
        return _putchar('0');

    /* Print the hexadecimal representation starting from the first non-zero bit */
    for (; i >= 0; i--)
    {
        if (hex[i] < 10)
            count += _putchar(hex[i] + '0');
        else
            count += _putchar(hex[i] - 10 + 'a');
    }

    return count;
}
