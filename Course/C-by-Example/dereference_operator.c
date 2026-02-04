#include <stdio.h>

int main() {
    int x = 4;
    int* y = &x;
    printf("The value stored at x is %d\n", *y);
    return 0;
}
