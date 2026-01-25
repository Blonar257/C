#include <stdio.h>

int main() {
  char choise = '\0';
  float fahrenheit = 0.0f;
  float celsius = 0.0f;

  printf("Temperature Converter\n");
  printf("C - Celsius to Fahrenheit\n");
  printf("F - Fahrenheit to Celsius\n");
  printf("Choose conversion type:\n");
  scanf(" %c", &choise);

  if (choise == 'C' || choise == 'c') {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;
    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);

  } else if (choise == 'F' || choise == 'f') {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32.0f) * 5.0f / 9.0f;
    printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);

  } else {
    printf("Invalid choice!\n");
  }

  return 0;
}
