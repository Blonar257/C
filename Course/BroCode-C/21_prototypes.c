#include <stdbool.h>
#include <stdio.h>

void hello(char name[], int age);
bool ageCheck(int age);
// function prototype
// enables the use of the function before its definition

int main() {

  hello("Alice", 30);

  if (ageCheck(20)) {
    printf("You are an adult.\n");
  } else {
    printf("You are a minor.\n");
  }

  return 0;
}

void hello(char name[], int age) {
  printf("Hello %s, you are %d years old.\n", name, age);
}

bool ageCheck(int age) { return age >= 18; }
