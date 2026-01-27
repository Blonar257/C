#include <stdio.h>

typedef int Number;
typedef char FullName[50];
typedef char Initials[4];

int main() {

    Number num1 = 5;
    Number num2 = 6;

    FullName user1 = "Stefan Schrage";
    Initials user1_initials = "StS";

    printf("User 1: %s\n", user1);
    printf("Initials: %s\n", user1_initials);


    return 0;
}
