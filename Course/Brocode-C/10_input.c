#include <stdio.h>
#include <string.h>

int main() {
  char name[25];

  printf("Enter your name: ");
  // scanf("%s", &name);      // This will only read the first word
  fgets(name, 25, stdin); // This will read the entire line
  printf("Hello, %s!\n", name);

  name[strcspn(name, "\n")] =
      0; // Remove the newline character from the end of the string
  printf("Hello, %s!\n", name);

  name[strlen(name) - 1] = 0; // Remove the newline character from the end of
                              // the string -> another way
  printf("Hello, %s!\n", name);

  return 0;
}
