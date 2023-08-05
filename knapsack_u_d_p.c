#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int capacity, int weights[], int values[], int num_items) {
    int dp[num_items + 1][capacity + 1];

    // Initialize the DP table
    for (int i = 0; i <= num_items; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[num_items][capacity];
}

int main() {
    int num_items, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int weights[num_items], values[num_items];
    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d value: ", i + 1);
        scanf("%d", &values[i]);
    }

    int max_value = knapsack(capacity, weights, values, num_items);
    printf("Maximum value that can be obtained: %d\n", max_value);

    return 0;
}
