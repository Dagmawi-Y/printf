#include <stdio.h>
#include "main.h"

int main(void)
{
    int ret;

    ret = _printf("Test case 1: %d\n", 42);
    printf("Expected output 1: Test case 1: 42\n");
    printf("Actual output 1:   ");
    printf("Return value: %d\n\n", ret);

    ret = _printf("Test case 2: %+d\n", 42);
    printf("Expected output 2: Test case 2: +42\n");
    printf("Actual output 2:   ");
    printf("Return value: %d\n\n", ret);

    ret = _printf("Test case 3: % d\n", 42);
    printf("Expected output 3: Test case 3:  42\n");
    printf("Actual output 3:   ");
    printf("Return value: %d\n\n", ret);

    ret = _printf("Test case 4: %#o\n", 42);
    printf("Expected output 4: Test case 4: #52\n");
    printf("Actual output 4:   ");
    printf("Return value: %d\n\n", ret);


    ret = _printf("Test case 5: %+ d\n", 42);
    printf("Expected output 5: Test case 5: + 42\n");
    printf("Actual output 5:   ");
    printf("Return value: %d\n\n", ret);

    return 0;
}
