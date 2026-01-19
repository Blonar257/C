#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *datei;

    // --- Datei schreiben (Text) ---
    printf("--- Datei schreiben ---\n");
    datei = fopen("test.txt", "w");  // "w" = write (überschreibt)

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    fprintf(datei, "Hallo, Welt!\n");
    fprintf(datei, "Dies ist Zeile 2.\n");
    fprintf(datei, "Zahl: %d\n", 42);

    fclose(datei);
    printf("Datei 'test.txt' geschrieben.\n");

    // --- Datei anhängen ---
    printf("\n--- Datei erweitern ---\n");
    datei = fopen("test.txt", "a");  // "a" = append (anhängen)

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    fprintf(datei, "Diese Zeile wurde angehängt.\n");
    fclose(datei);
    printf("Zeile angehängt.\n");

    // --- Datei lesen (Zeichen für Zeichen) ---
    printf("\n--- Datei lesen (fgetc) ---\n");
    datei = fopen("test.txt", "r");  // "r" = read

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    char c;
    while ((c = fgetc(datei)) != EOF) {
        putchar(c);
    }

    fclose(datei);

    // --- Datei lesen (Zeile für Zeile) ---
    printf("\n--- Datei lesen (fgets) ---\n");
    datei = fopen("test.txt", "r");

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    char zeile[256];
    int zeilen_nr = 1;

    while (fgets(zeile, sizeof(zeile), datei) != NULL) {
        printf("%d: %s", zeilen_nr++, zeile);
    }

    fclose(datei);

    // --- Formatiert lesen ---
    printf("\n--- Formatiert lesen ---\n");

    // Erst Datei mit Daten erstellen
    datei = fopen("daten.txt", "w");
    fprintf(datei, "Max 25 1.75\n");
    fprintf(datei, "Anna 30 1.68\n");
    fprintf(datei, "Tom 22 1.82\n");
    fclose(datei);

    // Jetzt lesen
    datei = fopen("daten.txt", "r");

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    char name[50];
    int alter;
    float größe;

    printf("Name\tAlter\tGröße\n");
    printf("----\t-----\t-----\n");

    while (fscanf(datei, "%s %d %f", name, &alter, &größe) == 3) {
        printf("%s\t%d\t%.2f\n", name, alter, größe);
    }

    fclose(datei);

    // --- Binär-Datei schreiben ---
    printf("\n--- Binär-Datei schreiben ---\n");
    datei = fopen("daten.bin", "wb");  // "wb" = write binary

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    int zahlen[] = {10, 20, 30, 40, 50};
    fwrite(zahlen, sizeof(int), 5, datei);

    fclose(datei);
    printf("Binär-Datei geschrieben.\n");

    // --- Binär-Datei lesen ---
    printf("\n--- Binär-Datei lesen ---\n");
    datei = fopen("daten.bin", "rb");  // "rb" = read binary

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    int gelesene_zahlen[5];
    fread(gelesene_zahlen, sizeof(int), 5, datei);

    printf("Gelesene Zahlen: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", gelesene_zahlen[i]);
    }
    printf("\n");

    fclose(datei);

    // --- Dateigröße ermitteln ---
    printf("\n--- Dateigröße ---\n");
    datei = fopen("test.txt", "r");

    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    fseek(datei, 0, SEEK_END);  // Zum Ende springen
    long größe_bytes = ftell(datei);  // Position = Größe
    fseek(datei, 0, SEEK_SET);  // Zurück zum Anfang

    printf("Größe von test.txt: %ld Bytes\n", größe_bytes);

    fclose(datei);

    printf("\n--- Modi für fopen ---\n");
    printf("r   - Lesen (Datei muss existieren)\n");
    printf("w   - Schreiben (überschreibt/erstellt)\n");
    printf("a   - Anhängen (erstellt falls nicht existiert)\n");
    printf("r+  - Lesen und Schreiben\n");
    printf("w+  - Lesen und Schreiben (überschreibt)\n");
    printf("a+  - Lesen und Anhängen\n");
    printf("Binär: Füge 'b' hinzu (rb, wb, ab, etc.)\n");

    return 0;
}
