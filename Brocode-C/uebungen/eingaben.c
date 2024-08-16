#include <stdio.h>

int main() {
    char name[40] = "";
    
    printf("Bitte Namen eingeben:");
    fgets(name, 40, stdin);

    printf("Hallo %s", name);

    return 0;
}