#include <stdio.h>
#include <stdbool.h>

int main() {
    // Variables are used to store data
    // The data can be of different types
    // The type of the variable determines the size and layout of the variable's memory
    // The type of the variable also determines the range of values that can be stored within that memory
    // The type of the variable also determines the set of operations that can be applied to the variable

    char a = 'A';           // single character         %c  1 byte (-128 to 127)
    char b[] = "Hello";     // array of characters      %s  1 byte (-128 to 127)
    int c = 5;              // integer                  %d  4 bytes (-2,147,483,648 to 2,147,483,647)
    float d = 5.5;          // decimal number           %f  4 bytes (1.2E-38 to 3.4E+38)
    bool e = true;          // boolean                  %d  1 byte (0 to 255)
    float f = 5.512345;     // decimal number           %f  4 bytes (1.2E-38 to 3.4E+38)
    double g = 5.512345;    // decimal number           %f  8 bytes (1.7E-308 to 1.7E+308)
    short h = 5;            // integer                  %d  2 bytes (-32,768 to 32,767)
    long i = 5;             // integer                  %d  4 bytes (-2,147,483,648 to 2,147,483,647)

    short int j = 5;        // integer                  %d  2 bytes (-32,768 to 32,767)
    long int k = 5;         // integer                  %d  4 bytes (-2,147,483,648 to 2,147,483,647)
    unsigned int l = 5;     // integer                  %d  4 bytes (0 to 4,294,967,295)
    unsigned short int m = 5; // integer                %d  2 bytes (0 to 65,535)
    unsigned long int n = 5; // integer                 %d  4 bytes (0 to 4,294,967,295)
    long long int o = 5;    // integer                  %d  8 bytes (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)
    unsigned long long int p = 5; // integer             %d  8 bytes (0 to 18,446,744,073,709,551,615)


    printf("%0.2f\n", f); // 5.51

    return 0;
}