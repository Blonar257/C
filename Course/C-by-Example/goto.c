#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x < 3) goto cleanup;
    // Program code here
cleanup:
    return 0;
}
