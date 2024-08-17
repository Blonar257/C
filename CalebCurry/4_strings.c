#include <stdio.h>

int main() {

    char name[20];

    printf("Enter your name: ");
    scanf("%s", name); // %s is used to get strings
    // no & is used with name because name is an array

    printf("Hallo %s\n", name);

    return 0;
}
