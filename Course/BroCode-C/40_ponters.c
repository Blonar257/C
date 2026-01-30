#include <stdio.h>

void birthday(int *age);

int main() {
    int age = 25;

    birthday(&age);

    printf("Happy Birthday! You are now %d years old.\n", age);

    return 0;
}

void birthday(int *age) {
    *age = *age +1;
    // (*age)++;
    // geht beides
}
