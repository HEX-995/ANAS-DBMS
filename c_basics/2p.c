#include <stdio.h>

void countNotes(int amount) {
    // Define the denominations
    int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count[10] = {0}; // Array to store the count of each note

    // Loop through each denomination
    for (int i = 0; i < 10; i++) {
        if (amount >= notes[i]) {
            count[i] = amount / notes[i]; // Get the number of notes of this denomination
            amount = amount % notes[i]; // Update the remaining amount
        }
    }

    // Print the result
    printf("Minimum number of notes required:\n");
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            printf("₹%d: %d\n", notes[i], count[i]);
        }
    }
}

int main() {
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Please enter a valid amount.\n");
    } else {
        countNotes(amount);
    }

    return 0;
}
