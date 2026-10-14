#include <stdio.h>

void selection_sort(int arr[], int n);

int main()
{
    int arr[] = {6, 3, 8, 2, 7};
    int n = 5;

    printf("Before sorting: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    selection_sort(arr, n);

    printf("\nAfter sorting: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}