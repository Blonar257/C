#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};

    // Print the elements of the array
    for(int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, numbers[i]);
    }

    char grade[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int length = sizeof(grade) / sizeof(grade[0]);
    // Print the elements of the char array
    for(int i = 0; i < length; i++) {
        printf("Grade %d: %c\n", i, grade[i]);
    }

    return 0;
}
