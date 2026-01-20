#include <stdio.h>

void grüße(char name[]);
char name[] = "Stefan";
int fakultät(int nummer);

int main() {
  grüße(name);

  int test = fakultät(6);
  printf("\nTestergebnis: %d\n", test);

  return 0;
}

void grüße(char name[]) {
  printf("Hallo %s\n", name);
  printf("Alles klar?\n");
}

int fakultät(int nummer) {
  if (nummer <= 1) {
    return 1;
  } else {
    return nummer * fakultät(nummer - 1);
  }
}
