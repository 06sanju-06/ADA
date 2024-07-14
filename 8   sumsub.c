#include <stdio.h>

int count = 0; // Counter for number of subsets found


void subsetSum(int set[], int subset[], int n, int sum, int target, int index)
{
    if (sum == target)
    {
        printf("Subset %d:", ++count);
        for (int i = 0; i < index; i++)
        {
            printf("%3d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // If current sum exceeds the target or all elements have been considered
    if (index >= n || sum > target)
        return;

    // Include current element in the subset and recurse
    subset[index] = set[index];
    subsetSum(set, subset, n, sum + set[index], target, index + 1);

    // Exclude current element and recurse
    subset[index] = 0; // Backtrack: remove the element from subset
    subsetSum(set, subset, n, sum, target, index + 1);
}

int main() {
    int set[] = {10,13, 12, 20, 5};
    int n = 5;
    int target = 25;
    int subset[30] = {0}; // Array to store subsets, initialized with zeros

    printf("Subsets with sum equal to %d:\n", target);
    subsetSum(set, subset, n, 0, target, 0);

    return 0;
}
