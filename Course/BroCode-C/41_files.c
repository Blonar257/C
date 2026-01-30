#include <stdio.h>

int main() {
    // writing a file
    FILE *pFile = fopen("output.txt", "a");
    char text[] = "Bald ist Wochenende...\n";

    if(pFile == NULL) {
        printf("Error opening the file!");
        return 1;
    }

    fprintf(pFile, "%s", text);
    printf("written successfully.\n");

    fclose(pFile);

    // reading a file
    FILE *pFile2 = fopen("output.txt", "r");
    char buffer[1024] =  {0};

    if(pFile2 == NULL) {
        printf("Error opening the file!");
        return 1;
    }
    while(fgets(buffer, sizeof(buffer), pFile2) != NULL) {
        printf("%s", buffer);
    }
    fclose(pFile2);

    return 0;
}
