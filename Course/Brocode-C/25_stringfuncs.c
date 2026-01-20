#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[] = "Bro";
    char str2[] = "Code";

    // strcmp() function
    // It compares two strings and returns 0 if they are equal.
    // It returns a positive value if the first string is greater than the second string.
    // It returns a negative value if the first string is less than the second string.
    int result = strcmp(str1, str2);
    printf("strcmp() result: %d\n", result);

    // strcpy() function
    // It copies the second string to the first string.
    char str3[10];
    strcpy(str3, str1);
    printf("strcpy() result: %s\n", str3);

    // strcat() function
    // It concatenates the second string to the first string.
    char str4[10] = "Bro";
    char str5[] = "Code";
    strcat(str4, str5);
    printf("strcat() result: %s\n", str4);

    // strlen() function
    // It returns the length of the string.
    int length = strlen(str4);
    printf("strlen() result: %d\n", length);

    
    return 0;
}