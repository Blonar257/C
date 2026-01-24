#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    // String-Deklarationen
    char str1[50] = "Hallo";
    char str2[] = "Welt";
    char str3[50];

    // strlen - Länge ermitteln
    printf("--- String-Länge ---\n");
    printf("Länge von '%s': %zu\n", str1, strlen(str1));

    // strcpy - String kopieren
    printf("\n--- String kopieren ---\n");
    strcpy(str3, str1);
    printf("str3 nach strcpy: %s\n", str3);

    // strncpy - Sicherer kopieren (begrenzte Länge)
    strncpy(str3, "Linux", 49);
    str3[49] = '\0';  // Null-Terminator sicherstellen
    printf("str3 nach strncpy: %s\n", str3);

    // strcat - String anhängen
    printf("\n--- String verketten ---\n");
    strcpy(str3, "Hallo ");
    strcat(str3, "Welt");
    printf("Nach strcat: %s\n", str3);

    // strncat - Sicher anhängen
    strncat(str3, "!", 1);
    printf("Nach strncat: %s\n", str3);

    // strcmp - Strings vergleichen
    printf("\n--- String vergleichen ---\n");
    char s1[] = "Apple";
    char s2[] = "Banana";
    char s3[] = "Apple";

    printf("strcmp('%s', '%s') = %d\n", s1, s2, strcmp(s1, s2));
    printf("strcmp('%s', '%s') = %d\n", s1, s3, strcmp(s1, s3));
    printf("strcmp('%s', '%s') = %d\n", s2, s1, strcmp(s2, s1));

    // Erklärung: <0 wenn s1 < s2, 0 wenn gleich, >0 wenn s1 > s2

    // strchr - Zeichen finden
    printf("\n--- Zeichen finden ---\n");
    char text[] = "Programmieren in C";
    char *pos = strchr(text, 'r');
    if (pos != NULL) {
        printf("Erstes 'r' an Position: %ld\n", pos - text);
    }

    // strstr - Substring finden
    printf("\n--- Substring finden ---\n");
    char *sub = strstr(text, "in C");
    if (sub != NULL) {
        printf("'in C' gefunden: %s\n", sub);
    }

    // String in Zahl umwandeln
    printf("\n--- String zu Zahl ---\n");
    char zahl_str[] = "12345";
    int zahl = atoi(zahl_str);
    printf("String '%s' als int: %d\n", zahl_str, zahl);

    char float_str[] = "3.14159";
    double d = atof(float_str);
    printf("String '%s' als double: %.5f\n", float_str, d);

    // Zahl in String umwandeln
    printf("\n--- Zahl zu String ---\n");
    char buffer[50];
    int wert = 42;
    sprintf(buffer, "Die Antwort ist %d", wert);
    printf("%s\n", buffer);

    // Zeichen-Funktionen (ctype.h)
    printf("\n--- Zeichen-Funktionen ---\n");
    char c = 'a';
    printf("'%c' ist Kleinbuchstabe: %d\n", c, islower(c));
    printf("'%c' zu Großbuchstabe: %c\n", c, toupper(c));

    // String durchlaufen und modifizieren
    printf("\n--- String modifizieren ---\n");
    char wort[] = "linux";
    printf("Original: %s\n", wort);

    for (int i = 0; wort[i] != '\0'; i++) {
        wort[i] = toupper(wort[i]);
    }
    printf("Großbuchstaben: %s\n", wort);

    // String tokenisieren (aufteilen)
    printf("\n--- String tokenisieren ---\n");
    char satz[] = "Dies ist ein Test";
    char *token = strtok(satz, " ");

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    // Benutzereingabe
    printf("\n--- Eingabe lesen ---\n");
    char eingabe[100];
    printf("Gib deinen Namen ein: ");
    fgets(eingabe, sizeof(eingabe), stdin);

    // Newline entfernen
    eingabe[strcspn(eingabe, "\n")] = '\0';
    printf("Hallo, %s!\n", eingabe);

    return 0;
}
