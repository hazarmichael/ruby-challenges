#include <stdio.h>

int main() {
    int n1 = 0, n2 = 1, next, terms;

    // Ask the user for the number of terms
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &terms);

    // Ensure user input is valid
    if (terms < 2) {
        printf("The sequence must contain at least two terms.\n");
        return 1;
    }

    // Print the first two terms of the sequence
    printf("Fibonacci Sequence: %d, %d", n1, n2);

    // Generate the Fibonacci sequence up to the number of terms provided by the user
    for (int i = 3; i <= terms; ++i) {
        next = n1 + n2;  // The next Fibonacci number is the sum of the previous two
        printf(", %d", next);
        n1 = n2;  // Move n2 to n1
        n2 = next;  // Move next to n2
    }

    // Calculate and display the next number after the sequence
    next = n1 + n2;
    printf("\nThe next number in the Fibonacci sequence is: %d\n", next);

    return 0;
}
