#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low], j = high + 1, i = low;
    while (i < j)
    {
        do
        {
            i++;
        } while (i <= high && arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("The elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quick_sort(arr, 0, n - 1);

    printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}