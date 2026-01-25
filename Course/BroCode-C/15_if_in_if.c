#include <stdbool.h>
#include <stdio.h>

int main() {
  float price = 10.00;
  bool isStudent = true; // 10% discount for students
  bool isSenior = false; // 20% discount for seniors

  if (isStudent) {
    price = price - (price * 0.10);
    printf("Student discount applied.\n");
  } else {
    if (isSenior) {
      price = price - (price * 0.20);
      printf("Senior discount applied.\n");
    }
  }

  printf("Final price: $%.2f\n", price);

  return 0;
}
