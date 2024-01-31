#include "main.h"
#include <unistd.h>

/**
 * print_pointer - Print a pointer address
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    int count = 0;

    write(1, "0x", 2);
    count += 2;
    count += print_hex_address((unsigned long)ptr);

    return (count);
}

/**
 * print_hex_address - Print an address in hexadecimal format
 * @address: Address to print in hexadecimal
 *
 * Return: Number of characters printed
 */
int print_hex_address(unsigned long address)
{
    char hex[] = "0123456789abcdef";
    int count = 0;
    char buffer[16];  // Buffer to store the reversed address

    if (address == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    // Convert address to hexadecimal and store it in the buffer
    while (address != 0)
    {
        buffer[count] = hex[address % 16];
        address /= 16;
        count++;
    }

    // Print the reversed buffer
    while (count > 0)
    {
        count--;
        write(1, &buffer[count], 1);
    }

    return (count);
}
