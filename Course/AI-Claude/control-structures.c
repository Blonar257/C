#include <stdio.h>

int main() {
  // If-Else
  int zahl = 10;

  if (zahl > 0) {
    printf("%d ist positiv\n", zahl);
  } else if (zahl < 0) {
    printf("%d ist negativ\n", zahl);
  } else {
    printf("Die Zahl ist Null\n");
  }

  // For-Schleife
  printf("\nFor-Schleife (1-5):\n");
  for (int i = 1; i <= 5; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // While-Schleife
  printf("\nWhile-Schleife (Countdown):\n");
  int countdown = 5;
  while (countdown > 0) {
    printf("%d... ", countdown);
    countdown--;
  }
  printf("Start!\n");

  // Do-While-Schleife
  printf("\nDo-While-Schleife:\n");
  int n = 1;
  do {
    printf("%d ", n);
    n++;
  } while (n <= 3);
  printf("\n");

  // Switch-Case
  char note = 'F';
  printf("\nNote %c: ", note);
  switch (note) {
  case 'A':
    printf("Sehr gut!\n");
    break;
  case 'B':
    printf("Gut!\n");
    break;
  case 'C':
    printf("Befriedigend\n");
    break;
  default:
    printf("Unbekannte Note\n");
  }

  return 0;
}
