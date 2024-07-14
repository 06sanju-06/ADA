#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[100000],b[100000];

// Function to merge two subarrays of arr[]
void merge(int low, int mid, int h)
{
    int i,j,k;
		i=low;
		j=mid+1;
		k=low;
		while(i<=mid && j <= h)
		{
			if(arr[i] <= arr[j])
			{
				b[k++]=arr[i++];
			}
			else
			{
				b[k++]=arr[j++];
			}
		}
		while(i<=mid)
		{
			b[k++]=arr[i++];
		}
		while(j<=h)
		{
			b[k++]=arr[j++];
		}
		for(i=low; i<=h;i++)
			arr[i]=b[i];
}

void mergeSort( int low, int high) {
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    srand(time(0));  // Seed for random number generator
    for (int n = 5000; n <= 100000; n += 5000)
    {
        for (int i = 0; i < n; i++)
        {
            //arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
            arr[i]=n-i;
        }
        clock_t start, end;
        double cpu_time_used;

        start = clock();
        mergeSort(0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

    }

    return 0;
}

