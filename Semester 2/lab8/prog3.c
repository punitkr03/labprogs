// Program to implement heap sort.
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

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n = 8;
    int arr[] = {7, 6, 3, 2, 1, 8, 5, 4};

    printf("Before sorting:\n");
    display(arr, n);
    heapsort(arr, n);
    printf("After sorting:\n");
    display(arr, n);

    return 0;
}