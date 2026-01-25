#include <stdio.h>

void happyBirthday(int *age, char name[]) {
  *age = *age + 1;
  printf("\nHappy Birthday to You!\n");
  printf("Happy Birthday to You!\n");
  printf("Happy Birthday Dear %s!\n", name);
  printf("You are %d years old now!\n", *age);
}

int main() {
  char name[50] = "Stefan";
  int age = 54;

  happyBirthday(&age, name);
  happyBirthday(&age, name);

  return 0;
}
