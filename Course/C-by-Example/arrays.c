#include <stdio.h>

int main() {
    int my_array[5];
    int my_array_b[] = {0,1,2,3,4}; // You can init the array from it's elements. Size can be detected automatically here.

    size_t len = sizeof(my_array) / sizeof(my_array[0]);
    for(size_t i = 0; i < len; i++) {
        my_array[i] = i;
    }

    printf("%d\n", my_array[2]);
    return 0;
}
