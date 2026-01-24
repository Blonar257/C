#include <stdio.h>
#include <string.h>

int main() {
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[30] = "";

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Age: %d", age);

    printf("\nEnter your gpa: ");
    scanf("%f", &gpa);
    printf("GPA: %.2f", gpa);

    printf("\nEnter your grade: ");
    scanf(" %c", &grade);  // Note the space before %c to consume
    printf("Grade: %c", grade);

    printf("\nEnter your name: ");
    scanf("%s", name);  // Note: This will read until the first whitespace
    printf("Name: %s", name);

    getchar(); // To consume the leftover newline character
    printf("\nEnter your full name: ");
    fgets(name, sizeof(name), stdin); // Read full name with spaces
    name[strlen(name) - 1] = '\0'; // Remove the newline character

    printf("Full Name: %s", name);

    return 0;
}
