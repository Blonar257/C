#include <stdio.h>

int main() {
    char grade;

    printf("\nEnter a letter grade: ");
    scanf("%c", &grade);

    // more efficient than if else
    // switch statement
    // case is the value that we are checking

    switch(grade) {
        case 'A':
            printf("Perfect\n");
            break;
        case 'B':
            printf("you did good\n");
            break;
        case 'C':
            printf("you did okay\n");
            break;
        case 'D':
            printf("you could do better\n");
            break;
        default:
            printf("not correct input\n");
            break;

    }

    return 0;
}
