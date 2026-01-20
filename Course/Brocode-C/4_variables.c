#include <stdio.h>

int main() {
    // Variables are used to store data
    // The data can be of different types
    // The type of the variable determines the size and layout of the variable's memory
    // The type of the variable also determines the range of values that can be stored within that memory
    // The type of the variable also determines the set of operations that can be applied to the variable


    int a = 5; // declaration + initialization
    int b = 10; // int is a data type that can store whole numbers
    int c = a + b;
    printf("The sum of %d and %d is %d\n", a, b, c);

    float d = 5.5; // float is a data type that can store decimal numbers
    float e = 10.5;
    float f = d / e;
    printf("The division of %f and %f is %f\n", d, e, f);

    char g = 'A'; // single quotes for characters
    char h = 'B'; 
    char name[] = "John"; // array of characters
    printf("The characters are %c and %c\n", g, h);
    printf("The name is %s\n", name);

    // a format specifier is used to display the value of a variable
    // %d is used to display the value of an integer
    // %f is used to display the value of a float
    // %c is used to display the value of a character
    // %s is used to display the value of a string



    return 0;
    
}
