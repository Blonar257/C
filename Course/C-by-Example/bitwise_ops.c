#include <stdio.h>

int main() {
    unsigned char a = 5; // 00000101
    unsigned char b = 9; // 00001001
    printf("a & b = %d\n", a & b); // 00000001
    printf("a | b = %d\n", a | b); // 00001101
    printf("a ^ b = %d\n", a ^ b); // 00001100
    printf("~a = %d\n", a = ~a); // 11111010
    printf("b << 1 = %d\n", b << 1); // 00010010
    printf("b >> 1 = %d\n", b >> 1); // 00000100
    return 0;
}
