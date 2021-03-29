#include <stdio.h>
#include <malloc.h>

typedef struct CircularQueue
{
    int size, f, r, *arr;
} CQueue;

int main()
{
    CQueue q;
    int ch, element;
    printf("Enter the size of the Queue: ");
    scanf("%d", &q.size);
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    do
    {
        printf("\n\n0. exit\n");
        printf("\n1. Insert\n");
        printf("\n2. Delete\n");
        printf("\n3. Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            enQueue(&q, element);
            break;
        }
        case 2:
        {
            printf("Enter the element to delete: ");
            scanf("%d", &element);
            deQueue(&q, element);
            break;
        }
        case 3:
        {
            display(q);
        }
        default:
        {
            printf("\nInvalid choice!!\n");
        }
        }
    } while (ch);

    return 0;
}