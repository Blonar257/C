#include <stdio.h>

enum week { mon, tue, wed, thu, fri, sat, sun };

int main() {
  for (int i = mon; i <= sun; i++) {
    printf("%d\n", i);
    if (i == wed) {
      printf("the middle...\n");
    }
  }
  return 0;
}
