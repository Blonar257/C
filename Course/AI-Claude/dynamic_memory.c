#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int alter;
} Person;

int main() {
    // malloc - Memory Allocation
    printf("--- malloc ---\n");
    int *zahlen = (int*)malloc(5 * sizeof(int));

    if (zahlen == NULL) {
        printf("Speicher konnte nicht allokiert werden!\n");
        return 1;
    }

    // Werte zuweisen
    for (int i = 0; i < 5; i++) {
        zahlen[i] = (i + 1) * 10;
    }

    printf("Zahlen: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", zahlen[i]);
    }
    printf("\n");

    // calloc - Cleared Memory Allocation (initialisiert mit 0)
    printf("\n--- calloc ---\n");
    int *nullen = (int*)calloc(5, sizeof(int));

    if (nullen == NULL) {
        printf("Speicher konnte nicht allokiert werden!\n");
        free(zahlen);
        return 1;
    }

    printf("Calloc-Array (automatisch 0): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nullen[i]);
    }
    printf("\n");

    // realloc - Größe ändern
    printf("\n--- realloc ---\n");
    int *erweitert = (int*)realloc(zahlen, 10 * sizeof(int));

    if (erweitert == NULL) {
        printf("Realloc fehlgeschlagen!\n");
        free(zahlen);
        free(nullen);
        return 1;
    }

    zahlen = erweitert;  // Wichtig: Pointer aktualisieren

    // Neue Elemente hinzufügen
    for (int i = 5; i < 10; i++) {
        zahlen[i] = (i + 1) * 10;
    }

    printf("Erweitertes Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", zahlen[i]);
    }
    printf("\n");

    // Dynamische Structs
    printf("\n--- Dynamische Structs ---\n");
    Person *p = (Person*)malloc(sizeof(Person));

    if (p == NULL) {
        printf("Speicher konnte nicht allokiert werden!\n");
        free(zahlen);
        free(nullen);
        return 1;
    }

    strcpy(p->name, "Thomas");
    p->alter = 42;

    printf("Person: %s, %d Jahre\n", p->name, p->alter);

    // Dynamisches Array von Structs
    printf("\n--- Array von Structs ---\n");
    int anzahl = 3;
    Person *personen = (Person*)malloc(anzahl * sizeof(Person));

    if (personen == NULL) {
        printf("Speicher konnte nicht allokiert werden!\n");
        free(zahlen);
        free(nullen);
        free(p);
        return 1;
    }

    strcpy(personen[0].name, "Alice");
    personen[0].alter = 25;

    strcpy(personen[1].name, "Bob");
    personen[1].alter = 30;

    strcpy(personen[2].name, "Charlie");
    personen[2].alter = 35;

    for (int i = 0; i < anzahl; i++) {
        printf("%d. %s (%d Jahre)\n", i+1, personen[i].name, personen[i].alter);
    }

    // WICHTIG: Speicher freigeben
    printf("\n--- Speicher freigeben ---\n");
    free(zahlen);
    free(nullen);
    free(p);
    free(personen);
    printf("Alle Speicher freigegeben!\n");

    // Memory Leak Beispiel (NICHT SO MACHEN!)
    printf("\n--- Memory Leak Warnung ---\n");
    int *leak = (int*)malloc(100 * sizeof(int));
    // leak wird NICHT freigegeben - Memory Leak!
    // IMMER: free(leak);

    printf("Tipp: Nutze valgrind um Memory Leaks zu finden:\n");
    printf("  valgrind --leak-check=full ./programm\n");

    return 0;
}
