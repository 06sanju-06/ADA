#include <stdio.h>


int main() {
    float val[20], wt[20];
    int n,i,j,m,rem;
    int totalwt = 0;
    float profit = 0.0;
    int sel[20]={0};

    // Read number of items and capacity from user
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);

    // Read values and weights of items from user
    printf("Enter values and weights of %d items:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%f %f", &val[i], &wt[i]);
    }

    // Calculate value-to-weight ratios
    float ratios[20],t1,t2,t3;
    for (i = 0; i < n; i++)
    {
        ratios[i] = val[i] / wt[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ratios[j] < ratios[j + 1]) {
                t1 = ratios[j];
                ratios[j] = ratios[j + 1];
                ratios[j + 1] = t1;

                t2 = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = t2;

                t3 = val[j];
                val[j] = val[j + 1];
                val[j + 1] = t3;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (totalwt + wt[i] <= m)
        {
            totalwt += wt[i];
            profit += val[i];
            sel[i] = 1; // Mark item as selected
        }
        else
        {
            rem = m - totalwt;
            profit += val[i] * ((float) (rem) / wt[i]);
            wt[i]-=rem;
            sel[i] = 1;
            break;
        }
    }


    printf("Maximum Profit in knapsack = %.2f\n", profit);

    printf("Items selected in knapsack:\n");
    for (i = 0; i < n; i++) {
        if (sel[i] == 1) {
            printf("Value: %f, Weight: %f\n",val[i], wt[i]);
        }
    }

    return 0;
}
