#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
}Student;

void printStudent(Student student);

int main() {

    Student student1 = {"Stefan Schrage", 54, 3.22, true};
    Student student2 = {"Lina Schrage", 18, 4.55, true};
    strcpy(student1.name, "Felix Schrage");

    printStudent(student1);
    printStudent(student2);

    return 0;
}

void printStudent(Student student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.2f\n", student.gpa);
    printf("Full Time: %s\n", student.isFullTime ? "Yes" : "No"); //ternary
    printf("\n");
}
