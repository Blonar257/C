#include <stdio.h>
#include <stdlib.h>

int close_compare(int a, int b, int margin);

int main() {
    printf("Compare 4 - 9, Margin 2: %d", close_compare(4, 9, 2));

    return 0;
}

int close_compare(int a, int b, int margin) {
    if (abs(a-b) <= margin || a == b) {
        return 0;
    } else if (a < b) {
        return -1;
    } else {
        return 1;
    }
}
