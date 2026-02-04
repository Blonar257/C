#include <stdio.h>

struct my_struct {
    int x;
    int y;
};

int main() {
    struct my_struct object1;
    object1.x = 1;
    printf("%d\n", object1.x);
    return 0;
}
