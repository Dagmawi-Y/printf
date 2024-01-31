#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_binary - Print a number in binary
 * @n: Number to print
 *
 * Return: Number of binary digits printed
 */
int print_binary(unsigned int n)
{
    int count = 0;

    if (n / 2)
        count += print_binary(n / 2);

    write(1, &((char){n % 2 + '0'}), 1);
    return (count + 1);
}

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; *ptr; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) == 'b')
        {
            unsigned int num = va_arg(args, unsigned int);
            count += print_binary(num);
            ptr++;
        }
        else
        {
            write(1, ptr, 1);
            count++;
        }
    }

    va_end(args);
    return (count);
}
