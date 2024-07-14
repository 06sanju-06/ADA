#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to generate an array of random integers
void genrandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i]=i;
        //arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }
}

int main() {
    srand(time(0));  // Seed for random number generator
    for (int n = 5000; n <= 100000; n += 5000)
    {
        int* arr = (int*)malloc(n * sizeof(int));
        genrandom(arr, n);

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        selectionSort(arr, n);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;


        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

        free(arr);
    }


    return 0;
}

