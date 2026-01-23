#include <stdio.h>
#include <stdlib.h>
#include "dirsize.h"

int main(void) {
    // Hole das aktuelle Arbeitsverzeichnis
    char *current_dir = get_current_directory();
    if (!current_dir) {
        fprintf(stderr, "Fehler: Konnte aktuelles Verzeichnis nicht auslesen\n");
        return 1;
    }
    
    printf("=== Verzeichnisgröße ===\n");
    printf("Pfad: %s\n\n", current_dir);
    
    // Berechne Größe des aktuellen Verzeichnisses und aller Unterverzeichnisse
    DirectorySizeInfo size_info = calculate_dir_size(current_dir);
    
    // Formatiere die Größen für schöne Ausgabe
    char *formatted_current = format_size(size_info.current_dir_size);
    char *formatted_total = format_size(size_info.total_size);
    
    // Gebe die Ergebnisse aus
    printf("Größe des aktuellen Ordners (nur Dateien):  %s\n", formatted_current);
    printf("Größe mit allen Unterverzeichnissen:        %s\n\n", formatted_total);
    
    // Warnung wenn Verzeichnisse nicht zugänglich waren
    if (size_info.inaccessible_dirs > 0) {
        printf("⚠ Warnung: %d Verzeichnis(se) konnten nicht gelesen werden\n", 
               size_info.inaccessible_dirs);
    }
    
    // Cleanup
    free(current_dir);
    free(formatted_current);
    free(formatted_total);
    
    return 0;
}
