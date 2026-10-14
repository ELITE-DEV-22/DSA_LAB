#include <stdio.h>
void merge(int a[], int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid + 1;
    int b[100];

    while (h <= mid && j <= high)
    {
        if (a[h] < a[j])
            b[i++] = a[h++];
        else
            b[i++] = a[j++];
    }
    while (h <= mid)
        b[i++] = a[h++];
    while (j <= high)
        b[i++] = a[j++];
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}