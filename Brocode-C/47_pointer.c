#include <stdio.h>

// Advantages of pointers:
// 1. Pointers are used to access the memory address of a variable.
// 2. Pointers are used to access the value of a variable.
// 3. Less time in program execution.
// 4. Less memory consumption.
// 5. Pointers are used to access the value of a variable indirectly.

void printAge(int *pAge)
{
    printf("Age: %d\n", *pAge);
}

int main()
{
    int age = 21;
    int *pAge = NULL;
    pAge = &age; // geht auch ohne NULL ist aber besser
    // pointer = &variable
    //  * = indirection operator

    printf("Adress of age: %p\n", &age);
    // %p is used to print the address of the variable
    printf("Value of pAge: %p\n", pAge);

    printf("Size of Age: %ld bytes\n", sizeof(age));
    printf("Size of pAge: %ld bytes\n", sizeof(pAge));

    printf("Value of age: %d\n", age);
    printf("Value at stored Address: %d\n", *pAge); // dereferencing

    printAge(pAge);

    return 0;
}
