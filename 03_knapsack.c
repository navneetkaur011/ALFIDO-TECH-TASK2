#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

// Sorting items based on value per kg ratio (descending)
void sortItemsByRatio(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[j + 1].value / items[j + 1].weight;
            
            // Sort in descending order
            if (ratio1 < ratio2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Greedy Fractional Knapsack Algorithm implementation
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    sortItemsByRatio(items, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        // // If whole item fits, take it
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } 
        //If it doesn't fit completely, take the fractional part
        else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    printf("------FRACTIONAL KNAPSACK (GREEDY)------\n");
    printf("Enter the bag weight capacity: ");
    scanf("%d", &capacity);

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));
    for (int i = 0; i < n; i++) {
        printf("Enter Value and Weight for Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double maxProfit = fractionalKnapsack(capacity, items, n);
    printf("\nMaximum value we can get = %.2f\n", maxProfit);

    free(items);
    return 0;
}