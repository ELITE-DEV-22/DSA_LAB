#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int p, int q)
{
    int pivot = a[p];
    int up = p;
    int down = q;

    do
    {
        while (a[up] <= pivot && up < q)
            up++;

        while (a[down] > pivot)
            down--;

        if (up < down)
            swap(&a[up], &a[down]);

    } while (up < down);

    swap(&a[p], &a[down]);

    return down;
}

void quicksort(int a[], int p, int q)
{
    if (p < q)
    {
        int j = partition(a, p, q);

        quicksort(a, p, j - 1);
        quicksort(a, j + 1, q);
    }
}