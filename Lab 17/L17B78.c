#include "stdio.h"
#include "math.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *insert(struct node *, int);
struct node *createNode(int);
int isBalance(struct node *);
int height(struct node *);

int main()
{
    struct node *root = NULL;
    int choice, value, x, a;
    while (1)
    {
        printf("\n1. Insert\n2. Check Balance\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Node Value : ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            a = isBalance(root);
            printf(a ? "Balanced\n" : "Not Balanced\n");
            break;
        case 3:
            printf("---Exiting---");
            return 0;
        }
    }
    return 0;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lptr = newNode->rptr = NULL;
    return newNode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->info)
        root->lptr = insert(root->lptr, value);
    else if (value > root->info)
        root->rptr = insert(root->rptr, value);
    return root;
    // return root;
    // printf("Main : %d",root->info);
}

int isBalance(struct node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int lh = height(root->lptr);
    int rh = height(root->rptr);
    return abs(lh - rh) <= 1 && isBalance(root->lptr) && isBalance(root->rptr);
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + fmax(height(root->lptr), height(root->rptr));
}