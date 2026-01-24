#include <stdio.h>
#include <math.h>

int main() {
    double principal = 0.0;
    double rate = 0.0;
    int years = 0;
    int timesCompounded = 0;
    double total = 0.0;

    printf("Compound Interest Calculator\n");
    printf("============================\n");
    printf("Enter the principal (P): ");
    scanf("%lf", &principal);
    printf("Enter the interest rate (r): ");
    scanf("%lf", &rate);
    printf("Times compounded per year (n):");
    scanf("%d", &timesCompounded);
    printf("How many years (t): ");
    scanf("%d", &years);

    rate = rate / 100;
    total = principal * pow((1 + (rate / timesCompounded)), timesCompounded * years);
    printf("\nTotal amount after %d years: $%.2lf\n", years, total);

    return 0;
}
