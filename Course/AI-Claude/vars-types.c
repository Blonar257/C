#include <stdio.h>

int main() {
  // Ganzzahlen
  int alter = 25;
  long große_zahl = 1000000L;

  // Fließkommazahlen
  float pi = 3.14f;
  double präzise_pi = 3.14159265359;

  // Zeichen
  char buchstabe = 'A';

  // Ausgabe
  printf("Alter: %d\n", alter);
  printf("Große Zahl: %ld\n", große_zahl);
  printf("Pi (float): %f\n", pi);
  printf("Pi (double): %.10f\n", präzise_pi);
  printf("Buchstabe: %c\n", buchstabe);

  // Größe der Datentypen
  printf("\nGrößen in Bytes:\n");
  printf("int: %zu\n", sizeof(int));
  printf("long: %zu\n", sizeof(long));
  printf("float: %zu\n", sizeof(float));
  printf("double: %zu\n", sizeof(double));
  printf("char: %zu\n", sizeof(char));

  return 0;
}
