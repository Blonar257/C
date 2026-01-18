#include <stdio.h>

int main() {
  // Array deklarieren und initialisieren
  int zahlen[5] = {10, 20, 30, 40, 50};

  // Einzelne Elemente ausgeben
  printf("Erstes Element: %d\n", zahlen[0]);
  printf("Drittes Element: %d\n", zahlen[2]);

  // Alle Elemente durchlaufen
  printf("\nAlle Elemente:\n");
  for (int i = 0; i < 5; i++) {
    printf("zahlen[%d] = %d\n", i, zahlen[i]);
  }

  // Array-Größe berechnen
  int größe = sizeof(zahlen) / sizeof(zahlen[0]);
  printf("\nArray-Größe: %d\n", größe);

  // Summe berechnen
  int summe = 0;
  for (int i = 0; i < größe; i++) {
    summe += zahlen[i];
  }
  printf("Summe aller Elemente: %d\n", summe);

  // Strings (Char-Arrays)
  char name[] = "Linux";
  printf("\nName: %s\n", name);
  printf("Länge: %zu\n", sizeof(name)); // Inkl. Null-Terminator

  // Mehrdimensionale Arrays
  int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

  printf("\nMatrix:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
