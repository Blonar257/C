#include <stdio.h>
#include <math.h>

int main() {

    double A = sqrt(25);
    printf("The square root of 25 is %f\n", A);

    double B = pow(2, 3);
    printf("2 to the power of 3 is %f\n", B);

    double C = ceil(3.2);
    printf("The ceiling of 3.2 is %f\n", C);

    double D = floor(3.8);
    printf("The floor of 3.8 is %f\n", D);

    double E = fabs(-3.14);
    printf("The absolute value of -3.14 is %f\n", E);

    double F = fmod(5.3, 2);
    printf("The remainder of 5.3 divided by 2 is %f\n", F);

    return 0;
}