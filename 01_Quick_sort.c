#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For measuring execution runtime

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function: places the pivot element at its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The QuickSort Algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        quickSort(arr, low, pi - 1);  // Sort elements before partition
        quickSort(arr, pi + 1, high); // Sort elements after partition
    }
}

int main() {
    int size;
    printf("------QUICKSORT RUNTIME------\n");
    printf("Enter the number of elements to sort: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array based on user input size
    int* arr = (int*)malloc(size * sizeof(int));

    // Generate random numbers to test runtime objectively
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; 
    }

    printf("\nSorting Started, Please wait.... \n", size);

    // Start tracking clock cycles
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    // Stop tracking clock cycles
    clock_t stop = clock();
    // Calculate total time taken in milliseconds
    double duration = ((double)(stop - start) / CLOCKS_PER_SEC) * 1000;

    printf("Sorting done!\n");
    printf("Time Taken: %.2f milliseconds.\n\n", duration);

    // Free dynamically allocated memory
    free(arr);
    return 0;
}