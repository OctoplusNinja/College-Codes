#include <stdio.h>

void merge(int *arr, int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i]=arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i]=arr[m+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, int l, int r)
{
    if (l==r)
    {
        return;
    }
    int m = l+(r-l)/2;
    merge_sort(array, l,m);
    merge_sort(array, m+1, r);
    merge(array, l, m ,r);   
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
    
    merge_sort(arr, 0, n-1);

    printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}