#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed the random number generator with the current time

  int random_number = rand() % 10; // Generate a random number between 0 and 9
  int big_random_number =
      rand() % 1000; // Generate a random number between 0 and 999
  printf("Random number between 0 and 99: %d\n", random_number);
  printf("Random number between 0 and 999: %d\n", big_random_number);

  return 0;
}
