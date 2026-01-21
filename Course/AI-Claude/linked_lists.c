#include <stdio.h>
#include <stdlib.h>

// Knoten-Struktur
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Liste erstellen: Neuen Knoten am Anfang einfügen
Node* push_front(Node *head, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Speicher-Fehler!\n");
        return head;
    }

    new_node->data = value;
    new_node->next = head;
    return new_node;  // Neuer Kopf
}

// Am Ende einfügen
Node* push_back(Node *head, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Speicher-Fehler!\n");
        return head;
    }

    new_node->data = value;
    new_node->next = NULL;

    // Leere Liste?
    if (head == NULL) {
        return new_node;
    }

    // Zum Ende navigieren
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;

    return head;
}

// Element am Anfang löschen
Node* pop_front(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *new_head = head->next;
    free(head);
    return new_head;
}

// Liste ausgeben
void print_list(Node *head) {
    Node *current = head;
    printf("Liste: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Liste suchen
Node* find(Node *head, int value) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Element löschen (nach Wert)
Node* delete_value(Node *head, int value) {
    if (head == NULL) {
        return NULL;
    }

    // Erstes Element?
    if (head->data == value) {
        Node *new_head = head->next;
        free(head);
        return new_head;
    }

    // In der Mitte oder am Ende
    Node *current = head;
    while (current->next != NULL) {
        if (current->next->data == value) {
            Node *to_delete = current->next;
            current->next = current->next->next;
            free(to_delete);
            return head;
        }
        current = current->next;
    }

    return head;  // Nicht gefunden
}

// Liste umkehren
Node* reverse(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;  // Neuer Kopf
}

// Länge ermitteln
int length(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Gesamte Liste freigeben
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *list = NULL;

    printf("=== Verkettete Liste ===\n\n");

    // Elemente einfügen
    printf("Füge Elemente ein...\n");
    list = push_front(list, 3);
    list = push_front(list, 2);
    list = push_front(list, 1);
    print_list(list);

    list = push_back(list, 4);
    list = push_back(list, 5);
    print_list(list);

    // Länge
    printf("Länge: %d\n\n", length(list));

    // Suchen
    printf("Suche 3: ");
    Node *found = find(list, 3);
    if (found != NULL) {
        printf("Gefunden! Wert: %d\n\n", found->data);
    } else {
        printf("Nicht gefunden\n\n");
    }

    // Element löschen
    printf("Lösche 3...\n");
    list = delete_value(list, 3);
    print_list(list);

    // Erstes Element löschen
    printf("Lösche erstes Element...\n");
    list = pop_front(list);
    print_list(list);

    // Liste umkehren
    printf("\nKehre Liste um...\n");
    list = reverse(list);
    print_list(list);

    // Aufräumen
    printf("\nGebe Speicher frei...\n");
    free_list(list);
    printf("Fertig!\n");

    return 0;
}
