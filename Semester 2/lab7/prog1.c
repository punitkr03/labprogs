// Program to implement linear search in recursive and non recursive way.
#include <stdio.h>
#include <stdlib.h>

void linear_search(int arr[], int n, int target)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Element found at index %d.\n", i);
    else
        printf("Element not found.\n");
}

int linear_recursion(int arr[], int n, int target)
{
    if (n == 0)
        return -1;
    if (arr[n - 1] == target)
        return n - 1;
    return linear_recursion(arr, n - 1, target);
}

int main()
{
    int n = 7;
    int i, target=13;
    int arr[] = {2,7,9,12,13,25,64};
    linear_search(arr, n, target);
    int result = linear_recursion(arr, n, target);
    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);
    return 0;
}