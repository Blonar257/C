#include <stdio.h>

struct Person {
    int age;
    int height;
    int weight;
    char name[20];
};

float bmi(struct Person p);

int main() {
    struct Person stefan = {54, 191, 144, "Stefan"};

    float bmi_value = bmi(stefan);
    printf("BMI von %s vor der Diät: %.2f\n", stefan.name, bmi_value);

    stefan.weight = 120;
    bmi_value = bmi(stefan);
    printf("BMI von %s nach der Diät: %.2f\n", stefan.name, bmi_value);

    return 0;
}

float bmi(struct Person p) {
    float heightInMeters = p.height / 100.0;
    return p.weight / (heightInMeters * heightInMeters);
}
