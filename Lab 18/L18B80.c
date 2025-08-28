#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *createNode(int value);
struct node *insert(struct node *root, int value);
int max(struct node *root);
int min(struct node *root);

int main()
{
    struct node *root=NULL;
    int choice,value;
    while(1)
    {
        printf("1 To Insert \n2 To Find Max\n3 To Find Min\n4 To Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
             case 1:
            printf("Enter Node Value : ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
            case 2:
            int maximum = max(root);
            printf("Max Value : %d\n", maximum);
            break;
            case 3:
            int minimum = min(root);
            printf("Min Value : %d\n", minimum);
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}

int max(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return -1; // or any sentinel value
    }
    while (root->rptr != NULL)
    {
        root = root->rptr;
    }
    return root->info;
}
int min(struct node *root)
{
    if(root==NULL)
    {
       printf("Tree is empty.\n");
        return -1;
    }
    while (root->lptr != NULL)
    {
        root = root->lptr;
    }
    return root->info;
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
    {
        root = createNode(value);
    }
    if (root->info > value)
    {
        root->lptr = insert(root->lptr, value);
    }
    else if (root->info < value)
    {
        root->rptr = insert(root->rptr, value);
    }
    return root;
    // printf("Main : %d",root->info);
}