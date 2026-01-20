#include <stdio.h>

const float pi = 3.1415;
const char name[] = "Stefan";
const int age = 54;
const int dick = 1;
// bool kam erst später mit <stdbool.h>
// 1 = true, 0 = false

int main() {
  printf("Ein paar kleine Basics...\n");

  printf("Hallo mein Name ist %s\n", name);
  printf("Ich bin %d Jahre alt\n", age);

  if (dick == 1) {
    printf("Ich bin leider zu dick!\n");
  } else {
    printf("Ich bin sehr schlank!\n");
  }

  printf("\nPi: %.2f\n", pi); // 2 Nachkommastellen
  printf("Pi: %f\n", pi);

  int num = 1;
  while (num <= 5) {
    printf("Nummer: %d\n", num);
    num++;
  }

  return 0;
}
