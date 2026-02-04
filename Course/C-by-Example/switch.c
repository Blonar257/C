#include <stdio.h>

int main() {
    int x = 2;
    switch(x) {
    case 1:
        printf("One");
        break; // You must break the search or it will fall through to the next match.
    case 2:
        printf("Two");
        break;
    default: // If no match is found.
        break;
    }
    return 0;
}
