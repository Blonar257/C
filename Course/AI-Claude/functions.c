#include <stdio.h>

// Funktionsdeklaration (Prototyp)
int addiere(int a, int b);
void grüße(char name[]);
int fakultät(int n);

int main() {
  // Funktion aufrufen
  int summe = addiere(5, 3);
  printf("5 + 3 = %d\n", summe);

  grüße("Max");

  printf("Fakultät von 5: %d\n", fakultät(5));

  return 0;
}

// Funktionsdefinitionen
int addiere(int a, int b) { return a + b; }

void grüße(char name[]) { printf("Hallo, %s!\n", name); }

int fakultät(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * fakultät(n - 1); // Rekursion
}
