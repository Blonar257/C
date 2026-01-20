#include <stdio.h>

int main() {
    int lotto[6] = {12,23,44,13,5,7};
    int größe = sizeof(lotto) / sizeof(lotto[0]);

    printf("Das sind die aktuellen Lotto Zahlen:\n");
    for (int i=0; i <= größe-1; i++ ) {
        printf("%d. Zahl: %d\n", i+1, lotto[i]);
    }

    float schnitt = 0;
    for (int i = 0; i <= größe-1; i++) {
        schnitt = schnitt + lotto[i];
    }
    schnitt = schnitt / größe;
    printf("Durchschnitts-Zahl :%.2f\n", schnitt);


    return 0;
}
