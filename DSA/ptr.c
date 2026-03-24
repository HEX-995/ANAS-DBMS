#include <stdio.h>

struct Car {
    char model[50];
    int year;
    float price;
};

int main() {
    struct Car c1 = {"Toyota Corolla", 2022, 25000.5};
    struct Car *ptr = &c1;

    printf("Model: %p\n", ptr);
    printf("Model: %p\n", c1);
    printf("Year: %d\n", ptr->year);
    printf("Price: $%.2f\n", ptr->price);

    return 0;
}
