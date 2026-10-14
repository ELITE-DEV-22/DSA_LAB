#include <stdio.h>
#include <assert.h>

void insertion_sort(int arr[], int n);

int main()
{
    int arr[] = {6, 3, 8, 2, 7};
    int n = 5;

    insertion_sort(arr, n);

    assert(arr[0] == 2);
    assert(arr[1] == 3);
    assert(arr[2] == 6);
    assert(arr[3] == 7);
    assert(arr[4] == 8);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nAll insertion sort tests passed!\n");

    return 0;
}