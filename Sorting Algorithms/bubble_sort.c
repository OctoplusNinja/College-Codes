#include <stdio.h>

void bubble_sort(int *array, int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
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
    
    bubble_sort(arr, n);

    printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}