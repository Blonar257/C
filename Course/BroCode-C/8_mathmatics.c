#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float x = 9.1234;

    float a = sqrt(x);
    float b = pow(x, 3);
    float c = round(x);
    float d = ceil(x);
    float e = floor(x);
    float f = fmax(5, 10);
    float g = fmin(5, 10);
    float h = abs(-11);
    float i = sin(x);
    float j = cos(x);


    printf("sqrt %f -> %.2f", x, a);
    printf("\npow %f ^ 3 -> %.2f", x, b);
    printf("\nround %f -> %.2f", x, c);
    printf("\nceil %f -> %.2f", x, d);
    printf("\nfloor %f -> %.2f", x, e);
    printf("\nfmax 5, 10 -> %.2f", f);
    printf("\nfmin 5, 10 -> %.2f", g);
    printf("\nabs -11 -> %.2f", h);
    printf("\nsin %f -> %.2f", x, i);
    printf("\ncos %f -> %.2f", x, j);

    return 0;
}
