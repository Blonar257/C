#include <stdio.h>

int main() {
  char operator = '\0';
  double num1 = 0.0f;
  double num2 = 0.0f;
  double result = 0.0f;

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);
  printf("Enter two operands: ");
  printf("First number: ");
  scanf("%lf", &num1);
  printf("Second number: ");
  scanf("%lf", &num2);

  switch (operator) {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = num1 * num2;
    break;
  case '/':
    if (num2 != 0) {
      result = num1 / num2;
    } else {
      printf("Error: Division by zero is not allowed.\n");
    }
    break;
  default:
    printf("Error: Invalid operator.\n");
    break;
  }

  printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);

  return 0;
}
