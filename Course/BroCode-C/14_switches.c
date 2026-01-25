#include <stdio.h>

int main() {
  int dayofWeek = 0;

  printf("Enter a number (1-7) for the day of the week: ");
  scanf("%d", &dayofWeek);
  // scanf("%c", &dayofWeek); // for character input

  switch (dayofWeek) {
  case 1:
    // case '1': // for character input
    printf("Monday\n");
    break;
  case 2:
    printf("Tuesday\n");
    break;
  case 3:
    printf("Wednesday\n");
    break;
  case 4:
    printf("Thursday\n");
    break;
  case 5:
    printf("Friday\n");
    break;
  case 6:
    printf("Saturday\n");
    break;
  case 7:
    printf("Sunday\n");
    break;
  default:
    printf("Invalid day\n");
  }

  return 0;
}
