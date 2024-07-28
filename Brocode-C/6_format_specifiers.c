#include <stdio.h>

int main() {
    // format specifiers % = defines the type of data to be printed

    // %c = character
    // %s = string
    // %d = integer
    // %f = float
    // %lf = double
    // %x = hexadecimal
    // %o = octal
    // %u = unsigned integer
    // %p = pointer
    // %e = scientific notation

    // %.1 = 1 decimal place
    // %.2 = 2 decimal places
    // %1 = minimum width of 1
    // %- = left-justified
    // %0 = zero-padded
    // %* = width specified in an integer argument
    // %.* = precision specified in an integer argument
    // %n = number of characters printed so far

    float item1 = 5.512345;
    float item2 = 10.00;
    float item3 = 5.00;
    float item4 = 159.99;

    printf("Item 1: $%8.2f\n", item1); // Item 1: $5.51
    printf("Item 2: $%8.2f\n", item2); // Item 2: $10.00
    printf("Item 3: $%8.2f\n", item3); // Item 3: $5.00
    printf("Item 4: $%8.2f\n", item4); // Item 4: $159.99

    return 0;
}