#include <stdio.h>

static inline void square(int* x) {
    *x *= *x;
    return;
}

int main() {
    int num = 5;
    square(&num);
    printf("%d\n", num);
    return 0;
}
