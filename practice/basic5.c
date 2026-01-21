#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    printf("Bitte ALter eingeben: ");
    fgets(input, sizeof(input), stdin);

    char *check;
    int alter = strtol(input, &check, 10);
    // check gibt quasi zurück bis wohin konvertiert wurde

    // Fehlerprüfung
    if (check == input || *check != '\n') {
        printf("Ungültige Eingabe. Bitte eine Zahl eingeben.\n");
        return 1;
    } else if (alter <= 17) {
        printf("Nicht volljährig!");
    } else {
        printf("Volljährig!");
    }

    return 0;
}
