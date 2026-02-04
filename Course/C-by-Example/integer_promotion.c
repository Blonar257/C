#include <stdio.h>

int main() {
    char x = 'A';
    if (x < 'a') printf("Less than\n"); // x is promoted to int to compare it with the integer value of 'a'.
    else printf("Greater than or equal to\n");
    return 0;
}
