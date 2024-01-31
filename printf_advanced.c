#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "main.h"

/**
 * print_unsigned - Print an unsigned integer
 * @n: Unsigned integer to print
 * @buffer: Buffer for intermediate storage
 * @index: Index in the buffer
 *
 * Return: Updated index in the buffer
 */
int print_unsigned(unsigned int n, char *buffer, int index)
{
    int count = 0;

    if (n / 10)
        index = print_unsigned(n / 10, buffer, index);

    buffer[index++] = n % 10 + '0';
    return index;
}

/**
 * print_octal - Print an unsigned integer in octal
 * @n: Unsigned integer to print
 * @buffer: Buffer for intermediate storage
 * @index: Index in the buffer
 *
 * Return: Updated index in the buffer
 */
int print_octal(unsigned int n, char *buffer, int index)
{
    int count = 0;

    if (n / 8)
        index = print_octal(n / 8, buffer, index);

    buffer[index++] = n % 8 + '0';
    return index;
}

/**
 * print_hex - Print an unsigned integer in hexadecimal
 * @n: Unsigned integer to print
 * @buffer: Buffer for intermediate storage
 * @index: Index in the buffer
 * @uppercase: Flag to print uppercase hexadecimal letters
 *
 * Return: Updated index in the buffer
 */
int print_hex(unsigned int n, char *buffer, int index, int uppercase)
{
    char hex_digits[] = "0123456789abcdef";

    if (n / 16)
        index = print_hex(n / 16, buffer, index, uppercase);

    buffer[index++] = uppercase ? toupper(hex_digits[n % 16]) : hex_digits[n % 16];
    return index;
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
    char buffer[1024];
    int buffer_index = 0;

    va_start(args, format);

    for (ptr = format; *ptr; ptr++)
    {
        if (*ptr == '%' && (*(ptr + 1) == 'u' || *(ptr + 1) == 'o' || *(ptr + 1) == 'x' || *(ptr + 1) == 'X'))
        {
            unsigned int num = va_arg(args, unsigned int);
            switch (*(ptr + 1))
            {
                case 'u':
                    buffer_index = print_unsigned(num, buffer, buffer_index);
                    break;
                case 'o':
                    buffer_index = print_octal(num, buffer, buffer_index);
                    break;
                case 'x':
                    buffer_index = print_hex(num, buffer, buffer_index, 0);
                    break;
                case 'X':
                    buffer_index = print_hex(num, buffer, buffer_index, 1);
                    break;
            }
            ptr++;
        }
        else
        {
            buffer[buffer_index++] = *ptr;
        }

        if (buffer_index == 1024 - 1) // Flush the buffer when full
        {
            write(1, buffer, buffer_index);
            buffer_index = 0;
        }
    }

    write(1, buffer, buffer_index); // Flush any remaining content in the buffer
    va_end(args);
    return (count);
}
