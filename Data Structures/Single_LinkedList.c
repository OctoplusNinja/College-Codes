#include <stdio.h>
#include <malloc.h>

typedef struct SLL
{
    int info;
    struct SLL *next;
} node;

/*-----------Singly Linked List functions----------*/
void create(node **, int num);
void traverse(node *);
void insert_first(node **, int);
void insert_last(node **, int);
void insert_before(node **, int, int);
void insert_after(node **, int, int);
void insert_index(node **, int, int);
int count(node *);
void delete_first(node **);
void delete_last(node **);
void delete_index(node **, int);
void delete_element(node **, int);
void reverse(node **);

int main()
{
    node *head = NULL;
    int num, n, pos;
    do
    {
        printf("\nOperations to be performed:\n");
        printf("0. Exit\n");
        printf("1. Create\n");
        printf("2. Travserse\n");
        printf("3. Insert at the Start\n");
        printf("4. Insert at the End\n");
        printf("5. Insert before specific Element\n");
        printf("6. Insert after specific Element\n");
        printf("7. Insert at specific Index\n");
        printf("8. Count\n");
        printf("9. Delete at the Start\n");
        printf("10. Delete at the End\n");
        printf("11. Delete at Specific Index\n");
        printf("12. Delete a Specific Element\n");
        printf("13. Reverse the List\n");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            break;
        case 1:
        {
            printf("Enter the number of nodes: ");
            scanf("%d", &num);
            create(&head, num);
            break;
        }
        case 2:
        {
            traverse(head);
            break;
        }
        case 3:
        {
            printf("Enter the element: ");
            scanf("%d", &num);
            insert_first(&head, num);
            break;
        }
        case 4:
        {
            printf("Enter the element: ");
            scanf("%d", &num);
            insert_last(&head, num);
            break;
        }
        case 5:
        {
            printf("Enter the element: ");
            scanf("%d", &num);
            printf("Enter the element before which data to be inserted: ");
            scanf("%d", &pos);
            insert_before(&head, num, pos);
            break;
        }
        case 6:
        {
            printf("Enter the element: ");
            scanf("%d", &num);
            printf("Enter the element after which data to be inserted: ");
            scanf("%d", &pos);
            insert_after(&head, num, pos);
            break;
        }
        case 7:
        {
            printf("Enter the element: ");
            scanf("%d", &num);
            printf("Enter the Index: ");
            scanf("%d", &pos);
            insert_index(&head, num, pos);
            break;
        }
        case 8:
        {
            printf("Count: %d\n", count(head));
            break;
        }
        case 9:
        {
            delete_first(&head);
            break;
        }
        case 10:
        {
            delete_last(&head);
            break;
        }
        case 11:
        {
            printf("Enter the index: ");
            scanf("%d", &num);
            delete_index(&head, num);
            break;
        }
        case 12:
        {
            printf("Enter the Element: ");
            scanf("%d", &num);
            delete_element(&head, num);
            break;
        }
        case 13:
        {
            reverse(&head);
            break;
        }
        default:
            break;
        }
    } while (n);

    return 0;
}

void create(node **head, int num)
{
    int item;
    node *newnode, *temp;
    if (*head != NULL)
    {
        printf("\nThe list already exists...\n");
        return;
    }
    printf("Enter the elements: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &item);
        newnode = (node *)malloc(sizeof(node));
        newnode->info = item;
        newnode->next = NULL;
        if (*head == NULL)
            *head = newnode;
        else
            temp->next = newnode;
        temp = newnode;
    }
    printf("List Created!!\n");
    return;
}

void traverse(node *head)
{
    if (head == NULL)
    {
        printf("\nThe List is Empty!!\n");
        return;
    }
    printf("\nThe list is: ");
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
    return;
}

void insert_first(node **head, int num)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->info = num;
    newnode->next = *head;
    *head = newnode;
}

void insert_last(node **head, int num)
{
    node *newnode = (node *)malloc(sizeof(node)), *temp = *head;
    newnode->info = num;
    newnode->next = NULL;
    if (*head == NULL)
        *head = newnode;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

int count(node *head)
{
    int n = 0;
    while (head != NULL)
    {
        n++;
        head = head->next;
    }
    return n;
}

void delete_first(node **head)
{
    if (*head == NULL)
    {
        printf("\nThe List is Empty!!\n");
        return;
    }
    node *temp = *head;
    *head = temp->next;
    printf("\nDeleting Node containing info %d\n", temp->info);
    free(temp);
}

void delete_last(node **head)
{
    if (*head == NULL)
    {
        printf("The List is Empty!!\n");
        return;
    }
    node *temp = *head, *tempp;
    while (temp->next != NULL)
    {
        tempp = temp;
        temp = temp->next;
    }
    if (temp == *head)
    {
        *head = NULL;
    }
    else
    {
        tempp->next = NULL;
    }
    printf("Deleting Node containing info %d\n", temp->info);
    free(temp);
}

void delete_index(node **head, int index)
{
    if (*head == NULL)
    {
        printf("The List is Empty!!\n");
        return;
    }
    if (index > count(*head) || index <= 0)
    {
        printf("Invalid Index!!\n");
        return;
    }
    node *p = NULL, *q = *head;
    for (int i = 0; i < index - 1; i++)
    {
        p = q;
        q = q->next;
    }
    if (p == NULL)
    {
        *head = q->next;
    }
    else
        p->next = q->next;

    printf("\nDeleting Node containing info %d\n", q->info);
    free(q);
}

void delete_element(node **head, int element)
{
    if (*head == NULL)
    {
        printf("\nThe List is Empty!!\n");
        return;
    }
    node *q = *head, *p = NULL;
    while (q->info != element && q->next != NULL)
    {
        p = q;
        q = q->next;
    }
    if (q->info == element)
    {
        printf("\nDeleting Node containing info %d\n", q->info);
        if (q == *head)
            *head = q->next;
        else
            p->next = q->next;
        free(q);
        return;
    }
    else
        printf("\nElement not found!!\n");

    free(q);
}

void insert_before(node **head, int element, int position)
{
    if (*head == NULL)
    {
        printf("\nThe List is Empty!!\n");
        return;
    }
    node *q = *head, *p = NULL;
    while (q->info != position && q->next != NULL)
    {
        p = q;
        q = q->next;
    }
    if (q->info == position)
    {
        printf("Inserting Element %d before %d\n", element, position);
        node *newnode = (node *)malloc(sizeof(node));
        newnode->info = element;
        newnode->next = q;
        if (q == *head)
            *head = newnode;
        else
            p->next = newnode;
    }
    else
        printf("Element Not found!!!\n");
}

void insert_after(node **head, int element, int position)
{
    if (*head == NULL)
    {
        printf("\nThe List is Empty!!\n");
        return;
    }
    node *q = *head;
    while (q->info != position && q->next != NULL)
    {
        q = q->next;
    }
    if (q->info == position)
    {
        printf("Inserting Element %d after %d\n", element, position);
        node *newnode = (node *)malloc(sizeof(node));
        newnode->info = element;
        newnode->next = q->next;
        q->next = newnode;
    }
    else
        printf("Element Not found!!!\n");
}

void insert_index(node **head, int element, int index)
{
    if (*head == NULL)
    {
        printf("\nThe List is Empty!!\n");
        return;
    }
    if (index > count(*head) || index <= 0)
    {
        printf("Invalid Index!!\n");
        return;
    }
    node *p = NULL, *q = *head;
    for (int i = 0; i < index - 1; i++)
    {
        p = q;
        q = q->next;
    }
    printf("Inserting Element %d at position %d\n", element, index);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->info = element;
    newnode->next = q;
    if (q == *head)
        *head = newnode;
    else
        p->next = newnode;
}

void reverse(node **head)
{
    node *loc = *head;
    node *locn, *prev = NULL;
    while (loc != NULL)
    {
        locn = loc->next;
        loc->next = prev;
        prev = loc;
        loc = locn;
    }
    *head = prev;
    printf("List reversed!!\n");
}