#include <stdarg.h>
#include <unistd.h>
#include "main.h"

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
    char c, *str;

    va_start(args, format);

    for (ptr = format; *ptr; ptr++)
    {
        if (*ptr == '%' && (*(ptr + 1) == 'c' || *(ptr + 1) == 's'))
        {
            if (*(ptr + 1) == 'c')
                c = va_arg(args, int);
            else
                str = va_arg(args, char *);

            if (!str)
                str = "(null)";

            while (*str || (*(ptr + 1) == 'c' && ++count))
                write(1, (*(ptr + 1) == 'c') ? &c : str++, 1);

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
