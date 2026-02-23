#include <stdio.h>
#include <stdlib.h>

int main() {
  int *x = (int *)malloc(sizeof(int)); // pointer to a heap-reserved integer
  if (x) { // test that the memory was allocated before you use it
    printf("%p", x);
    free(x); // you must manually free any memory you allocated on the heap or
             // it will persist (memory leak)
  }
  return 0;
}
