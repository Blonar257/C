#include <stdio.h>

int main() {
    int radius;
    double area;

    printf("Enter the radius of the circle: ");
    scanf("%d", &radius); // & is used to get the address of the variable

    area = 3.14159 * radius * radius;

    printf("The area of the circle is %f\n", area);

    return 0;
}
