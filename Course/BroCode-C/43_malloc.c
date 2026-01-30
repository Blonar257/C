#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 0;

    printf("Enter the number of grades: ");
    scanf("%d", &number);

    char *grades = malloc(number * sizeof(char)); //
    if (grades == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < number; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf(" %c", &grades[i]);
    }

    printf("You entered the following grades:\n");
    for (int i = 0; i < number; i++) {
        printf("Grade %d: %c\n", i + 1, grades[i]);
    }


    free(grades); // returning memory to os
    grades = NULL;

    return 0;
}
