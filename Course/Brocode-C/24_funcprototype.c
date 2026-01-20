#include <stdio.h>

// Function prototype
// What is ist?
// It is a declaration of a function that tells the compiler about 
// the number of parameters the function takes, 
// data types of parameters and return type of the function.

void hello(char[], int); // Function prototype

int main() 
{
    char name[] = "Brocode";
    int age = 20;

    hello(name, age); // Function call

    return 0;
}


void hello(char name[], int age) // Function definition
{
    printf("Hello %s\n", name);
    printf("You are %d years old\n", age);
}