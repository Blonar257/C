#include <stdio.h>

enum Day {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

int main() {
    enum Day today = MONDAY;

    printf("Today is :%d\n", today);

    if (today == SATURDAY || today == SUNDAY) {
        printf("\nWEEKEND!!!");
    } else {
        printf("\nOh no. Still have to work...");
    }


    return 0;
}
