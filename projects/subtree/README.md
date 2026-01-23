# Directory Size Calculator

Eine einfache CLI-Anwendung in C zur Berechnung der Verzeichnisgröße.

## Features

- ✅ Zeigt die Größe des aktuellen Verzeichnisses (nur direkte Dateien)
- ✅ Zeigt die Gesamtgröße inkl. aller Unterverzeichnisse
- ✅ Ausgabe in Menschen-lesbarem Format (B, KB, MB, GB)
- ✅ Rekursive Verzeichniserkennung
- ✅ Symlinks werden ignoriert
- ✅ Fehlerbehandlung für unzugängliche Verzeichnisse
- ✅ Warnung wenn Verzeichnisse nicht gelesen werden konnten

## Installation

```bash
make
```

Dies erstellt das ausführbare Programm `dirsize`.

## Verwendung

```bash
./subtree
```

Das Programm wird im aktuellen Verzeichnis ausgeführt und gibt die Größeninformationen aus.

## Beispielausgabe

```
=== Verzeichnisgröße ===
Pfad: /home/user/myproject

Größe des aktuellen Ordners (nur Dateien):  2.45 MB
Größe mit allen Unterverzeichnissen:        15.67 MB

⚠ Warnung: 2 Verzeichnis(se) konnten nicht gelesen werden
```

## Projektstruktur

- `main.c` - Einstiegspunkt und Ausgabelogik
- `dirsize.c` - Implementierung der Größenberechnungsfunktionen
- `dirsize.h` - Header-Datei mit Funktionsdefinitionen
- `Makefile` - Build-Automatisierung

## Technische Details

### Funktionsweise

1. **Größenberechnung**: Die Funktion `calculate_dir_size()` durchläuft rekursiv das Verzeichnis und summiert die Dateigröße aller Dateien auf.

2. **Symlink-Handling**: Mit `lstat()` wird überprüft, ob ein Eintrag ein Symlink ist. Diese werden ignoriert.

3. **Fehlerbehandlung**: Verzeichnisse ohne Leseberechtigung werden gezählt und dem Benutzer mitgeteilt.

4. **Formatierung**: Die Funktion `format_size()` konvertiert Bytes in Menschen-lesbare Einheiten.

## Cleanup

```bash
make clean
```

Entfernt alle generierten Dateien (`.o` Objekt-Dateien und die ausführbare Datei).

## Anforderungen

- GCC/Clang (oder ein anderer C99-kompatibler Compiler)
