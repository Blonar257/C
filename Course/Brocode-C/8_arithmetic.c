#include <stdio.h>

int main() {
    // arithmetic operators
    // + = addition
    // - = subtraction
    // * = multiplication
    // / = division
    // % = modulus (remainder)
    // ++ = increment
    // -- = decrement


    int x = 10;
    int y = 3;

    printf("%d + %d = %d\n", x, y, x + y); // 10 + 3 = 13
    printf("%d - %d = %d\n", x, y, x - y); // 10 - 3 = 7
    printf("%d * %d = %d\n", x, y, x * y); // 10 * 3 = 30
    printf("%d / %d = %d\n", x, y, x / y); // 10 / 3 = 3

    float z = x / y;
    printf("%d / %d = %0.2f\n", x, y, z); // 10 / 3 = 3.00
    float a = (float)x / y;
    printf("%d / %d = %0.2f\n", x, y, a); // 10 / 3 = 3.33

    int b = x % y;
    printf("%d %% %d = %d\n", x, y, b); // 10 % 3 = 1

    return 0;
}