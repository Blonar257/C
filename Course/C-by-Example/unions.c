#include <stdio.h>

// unions can only contain 1 value at a time
// size of the union is the size of the largest member -> here 20
union my_data {
    int i;
    float f;
    char str[20];
};

int main() {
    union my_data object1;
    printf("Size of my_data union: %lu\n", sizeof(object1));
    return 0;
}
