#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_number - Print a number (int)
 * @n: Number to print
 *
 * Return: Number of digits printed
 */
int print_number(int n)
{
    int count = 0;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
        count++;
    }

    if (n / 10)
        count += print_number(n / 10);

    write(1, &((char){n % 10 + '0'}), 1);
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
        if (*ptr == '%' && (*(ptr + 1) == 'd' || *(ptr + 1) == 'i'))
        {
            int num = va_arg(args, int);
            count += print_number(num);
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
