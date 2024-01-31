#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);
    count = parse_format(format, args);
    va_end(args);

    return (count);
}

/**
 * parse_format - Parse the format string and print the corresponding values
 * @format: Format string containing conversion specifiers
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding null byte)
 */
int parse_format(const char *format, va_list args)
{
    int i = 0, count = 0;

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            count += handle_format(format[i], args);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    return (count);
}

/**
 * handle_format - Handle each conversion specifier and print corresponding value
 * @specifier: Conversion specifier character
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int handle_format(char specifier, va_list args)
{
    int count = 0;

    switch (specifier)
    {
        case 'c':
            count += print_char(args);
            break;
        case 's':
            count += print_string(args);
            break;
        case '%':
            write(1, "%", 1);
            count++;
            break;
        default:
            write(1, "%", 1);
            write(1, &specifier, 1);
            count += 2;
    }

    return (count);
}
