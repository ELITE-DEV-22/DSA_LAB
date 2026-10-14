#include <stdio.h>
void quicksort(int a[], int p, int q);
int main()
{
    int a[] = {6, 3, 8, 2, 7};
    int n = 5;

    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    quicksort(a, 0, n - 1);

    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}