#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>  // Include this header for NULL

#define BUFFER_SIZE 1024

/**
 * struct buffer - Buffer structure
 * @buffer: Buffer to store characters
 * @index: Current index in the buffer
 * @size: Size of the buffer
 */
typedef struct buffer
{
    char buffer[BUFFER_SIZE];
    int index;
    int size;
} buffer_t;

int _printf(const char *format, ...);
int parse_format(const char *format, va_list args);
int handle_format(char specifier, va_list args);

int print_char(va_list args);
int print_string(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_string_custom(va_list args);
int print_pointer(va_list args);
int print_reversed(va_list args);
int print_rot13(va_list args);

void init_buffer(buffer_t *buf);
int flush_buffer(buffer_t *buf);
void add_to_buffer(buffer_t *buf, char c);
void free_buffer(buffer_t *buf);

int _strlen(char *str);
int print_hex(int num);
int print_hex_address(unsigned long address);

int print_reversed_str(char *str);
int print_rot13_str(char *str);

#endif /* MAIN_H */
