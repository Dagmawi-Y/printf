#include "main.h"

/**
 * custom_printf - A custom printf function that handles various format specifiers.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int custom_printf(const char *format, ...)
{
	FormatInfo format_info[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_percent}, {"%i", print_int},
		{"%d", print_decimal}, {"%r", print_reverse},
		{"%R", print_rot13}, {"%b", print_binary},
		{"%u", print_unsigned}, {"%o", print_octal},
		{"%x", print_hex}, {"%X", print_HEX},
		{"%S", print_special_string}, {"%p", print_pointer}
	};

	va_list args;
	int format_index = 0, total_chars = 0;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[format_index] != '\0')
	{
		if (format[format_index] == '%')
		{
			int specifier_index = 0;

			while (specifier_index < 14)
			{
				if (starts_with(format + format_index, format_info[specifier_index].format))
				{
					total_chars += format_info[specifier_index].printer(args);
					format_index += string_length(format_info[specifier_index].format);
					break;
				}
				specifier_index++;
			}
		}
		else
		{
			_putchar(format[format_index]);
			total_chars++;
		}

		format_index++;
	}

	va_end(args);
	return (total_chars);
}

/**
 * starts_with - Check if a string starts with another string.
 * @str: The string to check.
 * @prefix: The prefix to check for.
 * Return: 1 if str starts with prefix, 0 otherwise.
 */
int starts_with(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
			return (0);
		prefix++;
		str++;
	}
	return (1);
}

/**
 * string_length - Calculate the length of a string.
 * @str: The string to measure.
 * Return: The length of the string.
 */
int string_length(const char *str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
