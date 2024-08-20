#include <stdio.h>
#include <ctype.h>

int main() {
    char unit;
    float temp;

    printf("\nIs the temp in (F) or (C)?: ");
    scanf("%c", &unit);

    unit = toupper(unit);

    if (unit == 'F') {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temp);
        printf("The temperature in Celsius is: %.2f\n", (temp - 32) * 5 / 9);
    } else if (unit == 'C') {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp);
        printf("The temperature in Fahrenheit is: %.2f\n", (temp * 9 / 5) + 32);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
