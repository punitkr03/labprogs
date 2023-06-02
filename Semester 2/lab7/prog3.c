// Program to implement bubble sort, selection sort and insertion sort.
#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", (arr[i]));
    printf("\n");
}
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    printf("Bubble sort : \n");
    for (i = 0; i < (n - 1); i++)
    {
        for (j = 0; j < n - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        display(arr, n);
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, temp, min;
    printf("Selection sort : \n");
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (i != min)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        display(arr, n);
    }
}

void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    printf("Insertion sort : \n");
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        display(arr, n);
    }
}

int main()
{
    int n = 7;
    int arr1[] = {13,9,2,12,7,64,25};
    int arr2[] = {13,9,2,12,7,64,25};
    int arr3[] = {13,9,2,12,7,64,25};
    bubble_sort(arr1, n);
    selection_sort(arr2, n);
    insertion_sort(arr3, n);

    return 0;
}