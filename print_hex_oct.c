#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * print_hex_oct - Handles %u, %o, %x, %X conversion specifiers
 * @format: Format string
 * @args: Variable argument list
 *
 * Return: Number of characters printed
 */
int print_hex_oct(const char *format, va_list args)
{
    int count = 0;
    const char *ptr;
    unsigned int num;

    for (ptr = format; *ptr != '\0'; ++ptr)
    {
        if (*ptr == '%' && (*(ptr + 1) == 'u' || *(ptr + 1) == 'o' || *(ptr + 1) == 'x' || *(ptr + 1) == 'X'))
        {
            switch (*(ptr + 1))
            {
                case 'u':
                    /* Assuming a reasonable buffer size */
                {
                    char buffer_u[20];
                    num = va_arg(args, unsigned int);
                    sprintf(buffer_u, "%u", num);
                    count += write(1, buffer_u, strlen(buffer_u));
                }
                    break;
                case 'o':
                    /* Assuming a reasonable buffer size */
                {
                    char buffer_o[20];
                    num = va_arg(args, unsigned int);
                    sprintf(buffer_o, "%o", num);
                    count += write(1, buffer_o, strlen(buffer_o));
                }
                    break;
                case 'x':
                case 'X':
                    /* Assuming a reasonable buffer size */
                {
                    char buffer_x[20];
                    num = va_arg(args, unsigned int);
                    sprintf(buffer_x, (*(ptr + 1) == 'x') ? "%x" : "%X", num);
                    count += write(1, buffer_x, strlen(buffer_x));
                }
                    break;
                default:
                    return (-1);
            }
            ++ptr;
        }
        else
        {
            count += write(1, ptr, 1);
        }
    }

    return (count);
}
