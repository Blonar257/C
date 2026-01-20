#include <stdio.h>

int main() {
    // argumented assignment operators
    // += = addition assignment
    // -= = subtraction assignment
    // *= = multiplication assignment
    // /= = division assignment
    // %= = modulus assignment

    int x = 10;
    int y = 3;

    x += y;
    printf("x += y: %d\n", x); // x += y: 13

    x -= y;
    printf("x -= y: %d\n", x); // x -= y: 10

    x *= y;
    printf("x *= y: %d\n", x); // x *= y: 30

    x /= y;
    printf("x /= y: %d\n", x); // x /= y: 10

    x %= y;
    printf("x %%= y: %d\n", x); // x %= y: 1

    return 0;
}