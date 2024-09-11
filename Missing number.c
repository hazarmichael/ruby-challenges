#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum and maximum values in the array
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Function to find the missing numbers in the series
void findMissingNumbers(int numbers[], int n) {
    int min, max;
    
    // Find the min and max values in the array
    findMinMax(numbers, n, &min, &max);
    
    // Create an array to mark present numbers
    int *present = (int *)calloc((max - min + 1), sizeof(int));

    // Mark the present numbers in the array
    for (int i = 0; i < n; i++) {
        present[numbers[i] - min] = 1;
    }

    // Check for missing numbers and print them
    printf("Missing numbers:\n");
    for (int i = 0; i <= max - min; i++) {
        if (!present[i]) {
            printf("%d ", i + min);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(present);
}

int main() {
    int *numbers = NULL;
    int size = 0;
    int input;

    printf("Enter the series of numbers (end with -1): \n");

    // Keep reading numbers until -1 is entered
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        
        // Dynamically reallocate memory to store the input
        numbers = (int *)realloc(numbers, (size + 1) * sizeof(int));
        if (numbers == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        numbers[size] = input;
        size++;
    }

    if (size == 0) {
        printf("No numbers were entered.\n");
    } else {
        // Call the function to find missing numbers
        findMissingNumbers(numbers, size);
    }

    // Free the allocated memory
    free(numbers);

    return 0;
}
