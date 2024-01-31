#include "main.h"
#include <unistd.h>

/**
 * parse_format - Parse the format string and handle conversion specifiers
 * @format: Format string
 * @args: Variable arguments list
 *
 * Return: Number of characters printed
 */
int parse_format(const char *format, va_list args)
{
    int count = 0;
    buffer_t buf;

    init_buffer(&buf);

    while (*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;
            count += handle_format(*format, args);
        }
        else
        {
            add_to_buffer(&buf, *format);
            count++;
        }

        format++;
    }

    count += flush_buffer(&buf);

    return count;
}

/**
 * handle_format - Handle a conversion specifier
 * @specifier: Conversion specifier
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int handle_format(char specifier, va_list args)
{
    int count = 0;
    buffer_t buf;

    switch (specifier)
    {
        case 'c':
            count += print_char(args);
            break;
        case 's':
            count += print_string(args);
            break;
        case '%':
            add_to_buffer(&buf, '%');
            count++;
            break;
        case 'd':
        case 'i':
            count += print_int(args);
            break;
        case 'b':
            count += print_binary(args);
            break;
        case 'u':
        case 'o':
        case 'x':
        case 'X':
            count += print_unsigned(args, specifier);
            break;
        case 'S':
            count += print_string_custom(args);
            break;
        case 'p':
            count += print_pointer(args);
            break;
        case 'r':
            count += print_reversed(args);
            break;
        case 'R':
            count += print_rot13(args);
            break;
        default:
            add_to_buffer(&buf, '%');
            add_to_buffer(&buf, specifier);
            count += 2;
            break;
    }

    return count;
}
