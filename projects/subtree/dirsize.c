#define _XOPEN_SOURCE 700

#include "dirsize.h"
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Hilfsfunktion: Recursively berechnet nur die Gesamtgröße
static void calculate_total_size_recursive(const char *path, uint64_t *total_size, 
                                           int *inaccessible) {
    DIR *dir = opendir(path);
    
    // Verzeichnis nicht zugänglich - Fehler vermerken
    if (!dir) {
        (*inaccessible)++;
        return;
    }
    
    struct dirent *entry;
    
    // Durchlaufe alle Einträge im aktuellen Verzeichnis
    while ((entry = readdir(dir)) != NULL) {
        // Ignoriere . und ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Konstruiere vollständigen Pfad
        char full_path[4096];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        struct stat file_stat;
        
        // Nutze lstat um Symlinks zu ignorieren
        if (lstat(full_path, &file_stat) == -1) {
            continue;
        }
        
        // Ignoriere Symlinks
        if (S_ISLNK(file_stat.st_mode)) {
            continue;
        }
        
        // Wenn es eine reguläre Datei ist, addiere die Größe
        if (S_ISREG(file_stat.st_mode)) {
            *total_size += file_stat.st_size;
        }
        // Wenn es ein Verzeichnis ist, rufe die Funktion rekursiv auf
        else if (S_ISDIR(file_stat.st_mode)) {
            calculate_total_size_recursive(full_path, total_size, inaccessible);
        }
    }
    
    closedir(dir);
}

// Berechnet die Verzeichnisgröße
DirectorySizeInfo calculate_dir_size(const char *path) {
    DirectorySizeInfo info = {0, 0, 0};
    uint64_t current_size = 0;
    uint64_t total_size = 0;
    int inaccessible = 0;
    
    DIR *dir = opendir(path);
    if (!dir) {
        return info;
    }
    
    struct dirent *entry;
    
    // Zähle nur die Dateien im aktuellen Verzeichnis (nicht rekursiv)
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char full_path[4096];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        struct stat file_stat;
        if (lstat(full_path, &file_stat) == -1) {
            continue;
        }
        
        if (S_ISLNK(file_stat.st_mode)) {
            continue;
        }
        
        // Nur reguläre Dateien im aktuellen Verzeichnis zählen
        if (S_ISREG(file_stat.st_mode)) {
            current_size += file_stat.st_size;
        }
    }
    
    closedir(dir);
    
    // Gesamtgröße berechnen (inkl. Unterverzeichnisse)
    total_size = current_size;
    calculate_total_size_recursive(path, &total_size, &inaccessible);
    
    info.current_dir_size = current_size;
    info.total_size = total_size;
    info.inaccessible_dirs = inaccessible;
    
    return info;
}

// Formatiert Bytes in Menschen-lesbares Format
char* format_size(uint64_t bytes) {
    char *result = malloc(32);
    if (!result) return NULL;
    
    const char *units[] = {"B", "KB", "MB", "GB"};
    double size = bytes;
    int unit_index = 0;
    
    // Wähle passende Einheit
    while (size >= 1024 && unit_index < 3) {
        size /= 1024;
        unit_index++;
    }
    
    snprintf(result, 32, "%.2f %s", size, units[unit_index]);
    
    return result;
}

// Gibt das aktuelle Arbeitsverzeichnis aus
char* get_current_directory(void) {
    char *cwd = malloc(4096);
    if (!cwd) return NULL;
    
    if (getcwd(cwd, 4096) == NULL) {
        free(cwd);
        return NULL;
    }
    
    return cwd;
}
