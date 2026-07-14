#include <stdio.h>
#include <stdlib.h>

// Standard Bubble Sort function to prepare user inputs for Binary Search
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Standard binary search logic
int binarySearch(int arr[], int n, int item) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == item) {
            return mid; // Found it
        }
        
        if (arr[mid] < item) {
            left = mid + 1; // Look in right half
        }
        
        else {
            right = mid - 1; // Look in left half
        }
    }
    return -1; // Element not found
}

int main() {
    int n, target;
    printf("------BINARY SEARCH------\n");
    printf("Enter Array size: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d numbers (separated by spaces): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array first 
    sortArray(arr, n);
    
    printf("\nSorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the number to search : ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    free(arr);
    return 0;
}