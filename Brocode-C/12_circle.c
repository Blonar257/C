#include <stdio.h>

int main() {
    int radius;
    const float pi = 3.14159;
    float area;
    float circumference;

    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    area = pi * radius * radius;
    circumference = 2 * pi * radius;

    printf("The area of the circle is: %.2f\n", area);
    printf("The circumference of the circle is: %.2f\n", circumference);

    return 0;
}