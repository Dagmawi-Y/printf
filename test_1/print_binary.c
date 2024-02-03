#include "main.h"
#include <stdarg.h>

/**
 * print_binary - Prints an unsigned integer in binary.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int binary[32];

    int i;

    /* Convert the integer to binary representation */
    for (i = 0; i < 32; i++)
    {
        binary[i] = num % 2;
        num /= 2;
    }

    /* Skip leading zeros */
    i = 31;
    while (i >= 0 && binary[i] == 0)
        i--;

    /* If the binary representation is 0, print a single '0' */
    if (i == -1)
        return _putchar('0');

    /* Print the binary representation starting from the first non-zero bit */
    for (; i >= 0; i--)
        count += _putchar(binary[i] + '0');

    return count;
}
