// Title: Hypotenuse of a right-angled triangle
// Description: A program that takes the length of the two sides of a right-angled triangle and calculates the length of the hypotenuse.

#include <stdio.h>
#include <math.h>

int main() {

    double a;
    double b;
    double c;

    printf("Enter the length of the first side: ");
    scanf("%lf", &a);
    printf("Enter the length of the second side: ");
    scanf("%lf", &b);

    c = sqrt(a * a + b * b);

    printf("The length of the hypotenuse is: %.2lf", c);

    return 0;
}