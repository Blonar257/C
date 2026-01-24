#include <stdio.h>

void times_two(int *x);

int main() {
    int x = 10;

    printf("Before: %d\n", x);
    times_two(&x);
    printf("After: %d\n", x);

    return 0;
}

void times_two(int *x) {
    *x = *x * 2;
}
