#include <stdio.h>

// --- #define - Konstanten ---
#define PI 3.14159
#define MAX_SIZE 100
#define PROGRAMM_NAME "MeinProgramm"

// --- #define - Makros ---
#define QUADRAT(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_VAR(var) printf(#var " = %d\n", var)

// --- Bedingte Kompilierung ---
#define DEBUG 1
#define VERSION 2

int main() {
    // Konstanten verwenden
    printf("--- Konstanten ---\n");
    printf("PI = %.5f\n", PI);
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("Programm: %s\n", PROGRAMM_NAME);

    // Makros verwenden
    printf("\n--- Makros ---\n");
    int x = 5;
    printf("QUADRAT(%d) = %d\n", x, QUADRAT(x));
    printf("QUADRAT(3+2) = %d\n", QUADRAT(3+2));  // Klammern wichtig!

    int a = 10, b = 20;
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("MIN(%d, %d) = %d\n", a, b, MIN(a, b));

    // Stringification (#)
    printf("\n--- Stringification ---\n");
    int zahl = 42;
    PRINT_VAR(zahl);

    // Bedingte Kompilierung
    printf("\n--- Bedingte Kompilierung ---\n");

#ifdef DEBUG
    printf("DEBUG-Modus aktiviert!\n");
#endif

#ifndef RELEASE
    printf("Kein RELEASE-Build\n");
#endif

#if VERSION == 1
    printf("Version 1\n");
#elif VERSION == 2
    printf("Version 2\n");
#else
    printf("Unbekannte Version\n");
#endif

    // Vordefinierte Makros
    printf("\n--- Vordefinierte Makros ---\n");
    printf("Datei: %s\n", __FILE__);
    printf("Zeile: %d\n", __LINE__);
    printf("Datum: %s\n", __DATE__);
    printf("Zeit: %s\n", __TIME__);

    // Beispiel mit Debugging
    printf("\n--- Debug-Beispiel ---\n");

#ifdef DEBUG
    #define LOG(msg) printf("[DEBUG:%d] %s\n", __LINE__, msg)
#else
    #define LOG(msg)  // Im Release-Modus: nichts tun
#endif

    LOG("Programm gestartet");
    int ergebnis = QUADRAT(7);
    LOG("Berechnung durchgeführt");
    printf("Ergebnis: %d\n", ergebnis);
    LOG("Programm beendet");

    return 0;
}

// Hinweis: Kompiliere mit -D Flag um Makros zu setzen:
// gcc preprocessor.c -o preprocessor -DRELEASE
// gcc preprocessor.c -o preprocessor -DDEBUG=0
