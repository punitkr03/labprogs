// Program to implement quick sort.
#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[e]);
    return i + 1;
}

void quicksort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quicksort(arr, s, p - 1);
        quicksort(arr, p + 1, e);
    }
}

int main()
{
    int n = 8;
    int arr[] = {7, 6, 3, 2, 1, 8, 5, 4};

    printf("Before sorting:\n");
    display(arr, n);
    quicksort(arr, 0, n - 1);
    printf("After sorting:\n");
    display(arr, n);

    return 0;
}