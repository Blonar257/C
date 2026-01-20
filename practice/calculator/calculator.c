#include <stdint.h>
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
void eingabe();

int main()
{
    int start = 1;
    int a = 0;
    int b = 0;

    while(start == 1)
    {
        printf("Calculator\n");
        printf("==========\n\n");
        printf("1- Addition\n");
        printf("2- Substraction\n");

        char choice = scanf("Choice: ");
        printf("%s\n", &choice);

        start = 0;
    }


    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void eingabe()
{

}
