#include <stdio.h>

int main()
{
    // ternary operator
    // condition ? expression1 : expression2
    // if condition is true, expression1 is executed
    // if condition is false, expression2 is executed
    int a = 5;
    int b = 10;
    int c = 0;

    c = (a > b) ? a : b;
    printf("\n%d\n", c);

    return 0;
}