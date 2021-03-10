#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

/*-----------TREE functions----------*/
void insert(node **, int);
void preorder_traverse(node *);
void inorder_traverse(node *);
void postorder_traverse(node *);
void delete (node **, int);
int height(node *);
void bfs_display(node *);
void printLevel(node *, int);

/*-----------Utily functions--------*/
int max(int, int);

int main()
{
    int n, num;
    node *head = NULL;
    do
    {
        printf("\n\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Height\n");
        printf("4. Preorder Traverse\n");
        printf("5. Inorder Traverse\n");
        printf("6. Postorder Traverse\n");
        printf("7. Delete\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
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
        }
        case 2:
        {
            if (head == NULL)
                printf("The Tree is Empty!!\n");
            else
                bfs_display(head);
            break;
        }
        case 3:
        {
            int h = height(head);
            if (h == -1)
                printf("The Tree is Empty!!\n");
            else
                printf("Height of the tree: %d\n", h);
            break;
        }
        case 4:
        {
            if (head == NULL)
                printf("The Tree is Empty!!\n");
            else
                preorder_traverse(head);
            break;
        }
        case 5:
        {
            if (head == NULL)
                printf("The Tree is Empty!!\n");
            else
                inorder_traverse(head);
            break;
        }
        case 6:
        {
            if (head == NULL)
                printf("The Tree is Empty!!\n");
            else
                postorder_traverse(head);
            break;
        }
        case 7:
        {
            printf("\nEnter the Element you want to Delete: ");
            scanf("%d", &num);
            delete (&head, num);
            break;
        }
        default:
        {
            printf("\nInvalid choice!!\n");
        }
        }
    } while (n);

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
            printf("\nDuplicate Item!");
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
    printf("\n%d inserted into the tree succesfully!!", num);
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
        printf("Node containing %d doesn't exist!!\n", num);
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
    printf("%d Deleted!!\n", num);
    free(position);
    return;
}

int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

void bfs_display(node *root)
{
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j < (pow(2, h) - pow(2, i)) / 2; j++)
        {
            printf(" ");
        }
        printLevel(root, i);
        printf("\n");
    }
}

void printLevel(node *root, int level)
{
    if (root == NULL)
    {
        printf("- ");
        return;
    }
    if (level == 0)
        printf("%d ", root->data);
    else if (level > 0)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}