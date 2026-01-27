#include <stdio.h>

int main() {

    int scores[5] = {0};

    for(int i = 0; i < 5; i++) {
        printf("Enter score %d: ", i);
        scanf("%d", &scores[i]);
    }

    for(int i = 0; i < 5;i++) {
        printf("Score %d: %d\n", i, scores[i]);
    }

    return 0;
}
