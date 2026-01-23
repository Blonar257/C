#ifndef DIRSIZE_H
#define DIRSIZE_H

#include <stdint.h>

// Struktur für die Größenberechnung
typedef struct {
    uint64_t current_dir_size;      // Größe nur des aktuellen Verzeichnisses
    uint64_t total_size;            // Größe inkl. aller Unterverzeichnisse
    int inaccessible_dirs;          // Anzahl der Verzeichnisse ohne Zugriffsrechte
} DirectorySizeInfo;

// Berechnet die Verzeichnisgröße rekursiv
DirectorySizeInfo calculate_dir_size(const char *path);

// Formatiert Bytes in Menschen-lesbares Format (B, KB, MB, GB)
char* format_size(uint64_t bytes);

// Gibt das aktuelle Arbeitsverzeichnis aus
char* get_current_directory(void);

#endif
