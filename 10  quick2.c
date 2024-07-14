#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Pivot
    int i = (low);     // Index of smaller element
    int j=high;

    while(i<j)
    {
        do
        {
            i++;
        }while(arr[i]<pivot&&arr[i]<=high);
        do
        {
            j--;
        }while(arr[j]>pivot&&arr[j]>=low);
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate an array of random integers
void genrandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i]=i;
        //arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }
    //for(int k=0;k<n;k++)
      //      printf("%d\n",arr[k]);

}

int main() {
    srand(time(0));  // Seed for random number generator


    // Print header only if file is empty

   for (int n = 5000; n <= 100000; n += 5000)
    {
        int* arr = (int*)malloc(n * sizeof(int));

        genrandom(arr, n);

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        quickSort(arr, 0, n);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

        //for(int k=0;k<n;k++)
          //  printf("%d\n",arr[k]);
        free(arr);
    }

    return 0;
}

