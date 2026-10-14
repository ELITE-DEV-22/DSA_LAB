void selection_sort(int arr[], int n)
{
    int i, j, temp, min;
    for (i = 0; i <= n - 1; i++)
    {
        min = i;
    
    for (j = i + 1; j <= n - 1; j++)
    {
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
}
   
}