#include <stdio.h>
#include <stdbool.h>

int main() {
    int age = 54;
    printf("Age: %d", age);

    float gpa = 2.5;
    printf("\nGPA: %.2f", gpa);

    char grade = 'B';
    printf("\nGrade: %c", grade);

    double largeNumber = 12345678.9;
    printf("\nLarge Number: %.2lf", largeNumber);

    char name[] = "Bro Code";
    printf("\nName: %s", name);

    bool isMale = true;
    printf("\nIs Male: %d", isMale);

    return 0;
}

// int = whole numbers (4 bytes)
// float = decimal numbers (4 bytes)
// char = single characters (1 byte)
// double = large decimal numbers (8 bytes)
// char[] = array of characters / string
// bool = true or false (1 byte)
