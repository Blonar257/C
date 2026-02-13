#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...) {
  int total, i, temp;
  total = 0;
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    temp = va_arg(args, int);
    total += temp;
  }
  va_end(args);
  return total;
}

int main() {
  int numbers[3] = {5, 10, 15};
  int sum_of_numbers = sum(3, numbers[0], numbers[1], numbers[2]);
  printf("Sum of the array: %d\n", sum_of_numbers);
  return 0;
}
