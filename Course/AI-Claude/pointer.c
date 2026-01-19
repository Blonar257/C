#include <stdio.h>

void verdopple(int *ptr);
void tausche(int *a, int *b);

int main() {
    // Basis: Variable und Pointer
    int zahl = 42;
    int *ptr = &zahl;  // ptr speichert die Adresse von zahl

    printf("Wert von zahl: %d\n", zahl);
    printf("Adresse von zahl: %p\n", (void*)&zahl);
    printf("Wert von ptr (Adresse): %p\n", (void*)ptr);
    printf("Wert an der Adresse (*ptr): %d\n", *ptr);

    // Wert über Pointer ändern
    *ptr = 100;
    printf("\nNach *ptr = 100:\n");
    printf("zahl = %d\n", zahl);

    // Pointer und Funktionen
    printf("\n--- Pointer in Funktionen ---\n");
    int x = 5;
    printf("Vor verdopple: x = %d\n", x);
    verdopple(&x);
    printf("Nach verdopple: x = %d\n", x);

    // Zwei Werte tauschen
    int a = 10, b = 20;
    printf("\nVor tausche: a = %d, b = %d\n", a, b);
    tausche(&a, &b);
    printf("Nach tausche: a = %d, b = %d\n", a, b);

    // Pointer und Arrays
    printf("\n--- Pointer und Arrays ---\n");
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;  // Array-Name ist bereits ein Pointer

    printf("arr[0] = %d, *p = %d\n", arr[0], *p);
    printf("arr[1] = %d, *(p+1) = %d\n", arr[1], *(p+1));

    // Array mit Pointer durchlaufen
    printf("Array-Elemente: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    // Pointer-Arithmetik
    printf("\n--- Pointer-Arithmetik ---\n");
    int *ptr2 = arr;
    printf("*ptr2 = %d\n", *ptr2);
    ptr2++;  // Zeigt jetzt auf arr[1]
    printf("Nach ptr2++: *ptr2 = %d\n", *ptr2);
    ptr2 += 2;  // Zeigt jetzt auf arr[3]
    printf("Nach ptr2+=2: *ptr2 = %d\n", *ptr2);

    return 0;
}

void verdopple(int *ptr) {
    *ptr = *ptr * 2;
}

void tausche(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
