void selection_sort(int a[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
    }
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
}

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid + 1;
    int b[100];
    while (h <= mid && j <= high)
    {
        if (a[h] > a[j])
        {
            b[i++] = a[j++];
        }
        else
            b[i++] = a[h++];
    }
    while (h <= mid)
    {
        b[i++] = a[h++];
    }
    while (j <= high)
    {
        b[i++] = a[j++];
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int low, int high, int a[])
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
// quicksort

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int p, int q){
    int pivot = a[p];
    int up = p;
    int down = q;
    do{
        while (a[up]<=pivot && up <q)
            up++;
        while (a[down] > pivot)
            down--;
        if (up < down){
            swap(&a[up], &a[down]);
        }
    }while(up<down);
    swap(&a[p], &a[down]);
    return down;
}

void quicksort(int a[], int p, int q){
    if (p<q){
        int j = partition(a,p,q);
        quicksort(a,p,j-1);
        quicksort(a,j+1, q);
    }
}