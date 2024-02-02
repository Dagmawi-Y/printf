#include "main.h"

int main(void)
{
    char c = 'A';
    char *str = "Hello, World!";
    int num = 123;
    unsigned int uNum = 456;
    void *addr = (void *)0x12345678;

    _printf("Integer with plus flag: %+d\n", num);
    _printf("Integer with space flag: % d\n", num);

    _printf("Hexadecimal with hash flag: %#x\n", uNum);
    _printf("Hexadecimal with uppercase and hash flags: %#X\n", uNum);

    _printf("Octal with hash flag: %#o\n", uNum);

    _printf("Pointer address: %p\n", addr);

    _printf("Character: %c\n", c);
    _printf("String: %s\n", str);

    return 0;
}
