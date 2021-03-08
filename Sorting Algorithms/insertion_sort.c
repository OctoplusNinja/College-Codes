#include <stdio.h>

void insertion_sort(int *array, int N)
{
    int j, temp;
    for (int i = 1; i < N; i++)
    {
        temp=array[i];
        j=i-1;
        while (j>=0 && array[j]>temp)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
    
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d" , &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("The elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    insertion_sort(arr, n);

    printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}