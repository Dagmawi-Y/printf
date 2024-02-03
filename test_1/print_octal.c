#include "main.h"
#include <stdarg.h>

/**
 * print_octal - Prints an unsigned integer in octal.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int octal[32];

    int i;

    /* Convert the integer to octal representation */
    for (i = 0; i < 32; i++)
    {
        octal[i] = num % 8;
        num /= 8;
    }

    /* Skip leading zeros */
    i = 31;
    while (i >= 0 && octal[i] == 0)
        i--;

    /* If the octal representation is 0, print a single '0' */
    if (i == -1)
        return _putchar('0');

    /* Print the octal representation starting from the first non-zero bit */
    for (; i >= 0; i--)
        count += _putchar(octal[i] + '0');

    return count;
}
