#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

void insert(node **, int);
void preorder_traverse(node *);
void inorder_traverse(node *);
void postorder_traverse(node *);
void delete (node **, int);

int main()
{
    int n, num;
    node *head = NULL;
    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Preorder Traverse\n");
        printf("4. Inorder Traverse\n");
        printf("5. Postorder Traverse\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the number of elements you want to insert: ");
            scanf("%d", &num);
            int arr[100];
            printf("\nEnter the Elements you want to insert: ");
            for (int i = 0; i < num; i++)
            {
                scanf("%d", &arr[i]);
            }
            for (int i = 0; i < num; i++)
            {
                insert(&head, arr[i]);
            }
            break;
        case 2:
            printf("\nEnter the Element you want to insert: ");
            scanf("%d", &num);
            delete (&head, num);
            break;
        case 3:
            preorder_traverse(head);
            break;
        case 4:
            inorder_traverse(head);
            break;
        case 5:
            postorder_traverse(head);
            break;
        case 6:
            break;
        default:
            printf("\nInvalid choice!!\n");
        }
    } while (n != 6);

    return 0;
}

void insert(node **root, int num)
{
    node *temp, *position, *parent;
    parent = NULL;
    position = *root;
    while (position != NULL)
    {
        if (num == position->data)
        {
            printf("\nDuplicate Item!\n");
            return;
        }
        parent = position;
        if (num < position->data)
            position = position->left;
        else
            position = position->right;
    }
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
    if (parent == NULL)
    {
        *root = temp;
    }
    else if (num < parent->data)
        parent->left = temp;
    else
        parent->right = temp;
    printf("\n%d inserted into the tree succesfully!!\n", num);
    return;
}

void preorder_traverse(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void inorder_traverse(node *root)
{
    if (root != NULL)
    {
        inorder_traverse(root->left);
        printf("%d ", root->data);
        inorder_traverse(root->right);
    }
}

void postorder_traverse(node *root)
{
    if (root != NULL)
    {
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        printf("%d ", root->data);
    }
}

void delete (node **root, int num)
{
    node *parent, *position, *child, *succ, *parsucc;
    parent = NULL;
    position = *root;
    while (position != NULL && position->data != num)
    {
        parent = position;
        if (num < position->data)
            position = position->left;
        else
            position = position->right;
    }
    if (position == NULL)
    {
        printf("\nNode containing %d doesn't exist!!", num);
        return;
    }
    if (position->right == NULL && position->left == NULL)
    {
        child = NULL;
    }
    else if (position->right == NULL)
    {
        child = position->left;
    }
    else if (position->left == NULL)
    {
        child = position->right;
    }
    else
    {
        succ = position->right;
        while (succ->left != NULL)
        {
            parsucc = succ;
            succ = succ->left;
        }
        if (parsucc != position)
        {
            parsucc->left = succ->right;
            succ->right = position->right;
        }
        succ->left = position->left;
        child = succ;
    }
    if (parent == NULL)
        *root = child;
    else
    {
        if (position == parent->right)
            parent->right = child;
        else
            parent->left = child;
    }
    printf("\n%d Deleted!!\n", num);
    free(position);
    return;
}