// Program to implement binary search in recursive and non recursive way.
#include <stdio.h>
#include <stdlib.h>

void binary_iterative(int arr[], int target, int size)
{
    int i, s, e, mid = 0;
    s = 0;
    e = size - 1;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if (arr[mid] == target)
        {
            printf("Element found at index %d.\n", mid);
            break;
        }
        else if (arr[mid] > target)
            e = mid - 1;
        else if (arr[mid] < target)
            s = mid + 1;
        else
            printf("Element not found.\n");
    }
}

int binary_recursive(int arr[], int target, int s, int e)
{
    int mid;
    mid = (s + e) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binary_recursive(arr, target, s, mid - 1);
    else if (arr[mid] < target)
        return binary_recursive(arr, target, mid + 1, e);
    else
        return -1;
}

int main()
{
    int n = 5, i;
    int arr[n];
    for (i = 0; i < n; i++)
        arr[i] = i + 1;
    printf("Enter a number to search.\n");
    int target;
    scanf("%d", &target);

    binary_iterative(arr, target, n);

    int res = binary_recursive(arr, target, 0, n - 1);
    if (res >= 0)
        printf("Element found at index %d.\n", res);
    else
        printf("Element not found. \n");
    return 0;
}