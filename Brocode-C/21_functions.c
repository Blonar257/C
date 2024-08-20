#include <stdio.h>

void birthday(char name[], int age) 
{
    printf("\nHappy birthday to you %s!", name);
    printf("\nYou are %d years old now\n", age);
}

int main() 
{
    char name[] = "Bro";
    int age = 21;

    birthday(name, age);
 


    return 0;
}
