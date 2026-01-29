#include <stdio.h>
#include <stdlib.h>

int main() {

    int number = 0;
    printf("Number of players: ");
    scanf("%d", &number);

    //int *scores = malloc(number * sizeof(int));
    int *scores = calloc(number, sizeof(int));

    if(scores == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    for(int i = 0; i < number; i++) {
        printf("%d ", scores[i]);
    }

    free(scores);
    scores = NULL;

    return 0;
}
