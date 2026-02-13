#include <stdio.h>

union my_data {
  int i;
  float f;
  char str[20];
};

// union size is the size of the largest member
// only one member can contain a value at any given time

int main() {
  union my_data object1;
  printf("Size of my_data union: %lu\n", sizeof(object1));
  return 0;
}
