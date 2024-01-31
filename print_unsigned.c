#include "main.h"
#include <unistd.h>

/**
 * print_unsigned - Print an unsigned integer
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    count += print_unsigned(num, "0123456789");

    return (count);
}

/**
 * print_unsigned - Print an unsigned integer in a specified base
 * @num: Unsigned integer
 * @base: Base to print the number in
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_unsigned(unsigned int num, char *base)
{
    int count = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        count++;
    }

    while (num != 0)
    {
        write(1, &base[num % _strlen(base)], 1);
        num /= _strlen(base);
        count++;
    }

    return (count);
}
