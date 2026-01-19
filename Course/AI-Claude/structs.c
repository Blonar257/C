#include <stdio.h>
#include <string.h>

// Struct-Definition
struct Person {
    char name[50];
    int alter;
    float größe;
};

// Typedef für kürzere Schreibweise
typedef struct {
    int x;
    int y;
} Punkt;

// Funktionen mit Structs
void zeige_person(struct Person p);
void geburtstag(struct Person *p);
float abstand(Punkt p1, Punkt p2);

int main() {
    // Struct initialisieren
    struct Person person1;
    strcpy(person1.name, "Anna");
    person1.alter = 28;
    person1.größe = 1.68;

    // Direkte Initialisierung
    struct Person person2 = {"Max", 35, 1.82};

    // Designated Initializers (C99)
    struct Person person3 = {
        .name = "Lisa",
        .alter = 22,
        .größe = 1.65
    };

    printf("Person 1:\n");
    zeige_person(person1);

    printf("\nPerson 2:\n");
    zeige_person(person2);

    // Struct-Werte ändern
    printf("\n--- Geburtstag ---\n");
    printf("%s ist %d Jahre alt\n", person1.name, person1.alter);
    geburtstag(&person1);
    printf("%s ist jetzt %d Jahre alt\n", person1.name, person1.alter);

    // Typedef-Struct verwenden
    printf("\n--- Punkte ---\n");
    Punkt p1 = {0, 0};
    Punkt p2 = {3, 4};

    printf("Punkt 1: (%d, %d)\n", p1.x, p1.y);
    printf("Punkt 2: (%d, %d)\n", p2.x, p2.y);
    printf("Abstand: %.2f\n", abstand(p1, p2));

    // Array von Structs
    printf("\n--- Array von Personen ---\n");
    struct Person team[3] = {
        {"Alice", 30, 1.70},
        {"Bob", 25, 1.85},
        {"Carol", 28, 1.62}
    };

    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%d Jahre)\n", i+1, team[i].name, team[i].alter);
    }

    // Nested Structs
    typedef struct {
        Punkt position;
        char farbe[20];
    } Figur;

    Figur kreis = {{10, 20}, "Rot"};
    printf("\nFigur Position: (%d, %d), Farbe: %s\n",
           kreis.position.x, kreis.position.y, kreis.farbe);

    return 0;
}

void zeige_person(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Alter: %d Jahre\n", p.alter);
    printf("Größe: %.2f m\n", p.größe);
}

void geburtstag(struct Person *p) {
    p->alter++;  // Pfeiloperator für Pointer auf Structs
}

float abstand(Punkt p1, Punkt p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return __builtin_sqrt(dx*dx + dy*dy);
}
