 #include "stdio.h"
 #include <stdlib.h>
 struct node *insert(struct node *, int);
struct node *createNode(int);
void inOrder(struct node *root);
int compare(struct node *,struct node *);


struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};
int main()
{
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    int choice,value;
    while(1)
    {
        printf("1 To Insert in Tree 1\n2 To Insert in Tree 2\n3 To Display Tree 1(In Order)\n4 To Display Tree 2(In Order)0\n5 To Compare\n6 To Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter Node Value For Tree 1 : ");
            scanf("%d",&value);
            root1 = insert(root1,value);

            break;
            case 2:
            printf("Enter Node Value For Tree 2 : ");
            scanf("%d",&value);
            root2 = insert(root2,value);
            break;
            case 3:
            printf("Displaying Tree 1\n");
            inOrder(root1);
            printf("\n");
            break;
            case 4:
            printf("Displaying Tree 2\n");
            inOrder(root2);
            printf("\n");
            break;
            case 5:
           int a = compare(root1,root2);
           if(a==0)
           {
            printf("Same Trees\n");
           }
            break;
            case 6:
            printf("Exiting");
            return 0;
           default:
            return 0;
        }
    }
    return 0;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lptr=newNode->rptr=NULL;
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

}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->lptr);
    printf("%d-->", root->info);
    inOrder(root->rptr);
}

int compare(struct node *root1 , struct node *root2)
{
    if(root1==NULL || root2==NULL)
    {
        return 0;
    }

    if(root1->info != root2->info)
    {
        printf("Not Same\n");
        return 1;
    }
    else if(root1->info == root2->info){
        compare(root1->lptr,root2->lptr);
        compare(root1->rptr,root2->rptr);
    }
    // printf("%d-->", root->info);
}