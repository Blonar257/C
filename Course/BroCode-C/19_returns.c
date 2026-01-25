#include <stdio.h>

int square(int x) {
  // returning an integer value
  return x * x;
}

int getMax(int x, int y) {
  // returning the maximum of two integers
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int main() {
  int num1 = 5;

  int result = square(num1);
  printf("The square of %d is %d\n", num1, result);

  printf("The maximum between %d and %d is %d\n", 10, 20, getMax(10, 20));

  return 0;
}
