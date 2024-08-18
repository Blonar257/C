#include <stdio.h>

int main() {

    char ASCII;
    printf("please enter a char: ");
    scanf("%c", &ASCII);

    printf("Char: %c\n", ASCII);
    printf("ASCII: %i\n", ASCII);

    int integer;
    printf("please enter an integer: ");
    scanf("%i", &integer);

    printf("Integer: %i\n", integer);
    printf("ASCII: %c\n", integer);

    // Math with ASCII
    char mathz = 'A' + '\t';
    printf("A(65) + \\t(11) = %c(%d)\n", mathz, mathz);

    return 0;
}
