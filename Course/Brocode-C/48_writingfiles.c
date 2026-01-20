#include <stdio.h>

int main()
{
    FILE *fpointer = fopen("employees.txt", "w");

    fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar, Accountant");

    fclose(fpointer);

    if(remove("employees.txt") == 0)
    {
        printf("File deleted successfully\n");
    }
    else
    {
        printf("Error deleting file\n");
    }

    return 0;
}
