#include <stdio.h>

double square (double x) // void, double,int... vorne gibt an was zurück gegeben wird
{
    double result = x * x;
    return result;
}

int main()
{
    // return = returns a value back to the calling function
    double x = square(3.14);
    printf("\n%lf\n", x);

    return 0;
}