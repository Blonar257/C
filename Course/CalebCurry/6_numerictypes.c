#include <stdio.h>

int main() {

    // int
    int dogs = 2.5e4;

    // floating point numbers
    // double needs doeuble the memory of float
    // double is more precise than float
    // stored in scientific notation
    // 1.0e-6 = 0.000001
    // 1.0e6 = 1000000
    // 1.0e6 = 1.0 * 10^6 = 1000000

    printf("%i   %f   %f", dogs, 1111.1111, 1111.1111F);
    //   %i   %f   %f1   1111.111100   1111.111084

    return 0;
}
