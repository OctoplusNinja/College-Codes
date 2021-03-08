#include <stdio.h>

void selection_sort(int *array, int N)
{
    int loc, temp, min;
    for (int i = 0; i < N-1; i++)
    {
        min=array[i];
        loc=i;
        for (int j = i+1; j < N; j++)
        {
            if (min>array[j])
            {
                min=array[j];
                loc=j;
            }
        }
        temp = array[i];
        array[i] = array[loc];
        array[loc]=temp;
    }
    
}

int main()
{
    int N;
    printf("Enter the number of elements: ");
    scanf("%d" , &N);
    int arr[N];
    printf("Enter the elements: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    selection_sort(arr, N);
    printf("The sorted elements are: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}