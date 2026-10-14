#include <stdio.h>
#include <assert.h>

void mergesort(int a[], int low, int high);

int main()
{
    int a[] = {6, 3, 8, 2, 7};
    int n = 5;

    mergesort(a, 0, n - 1);

    assert(a[0] == 2);
    assert(a[1] == 3);
    assert(a[2] == 6);
    assert(a[3] == 7);
    assert(a[4] == 8);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nAll merge sort tests passed!\n");

    return 0;
}