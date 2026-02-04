#include <stdio.h>

int main() {
    int x[5];
    int* x_ptr = &x[0];
    printf("Value of x_ptr = %p\n", (void*)x_ptr);
    printf("Value of x_ptr + 1 = %p\n", (void*)(x_ptr + 1));
    char y[5];
    char* y_ptr = &y[0];
    printf("Value of y_ptr = %p\n", (void*)y_ptr);
    printf("Value of y_ptr + 1 = %p\n", (void*)(y_ptr + 1));
    return 0;
}
