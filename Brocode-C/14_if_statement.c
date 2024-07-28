#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int age;

    if (a > b) {
        printf("a is greater than b\n");
    } else {
        printf("a is less than or equal to b\n");
    }

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("You are an adult\n");
    } else {
        printf("You are a minor\n");
    }

    return 0;
}
