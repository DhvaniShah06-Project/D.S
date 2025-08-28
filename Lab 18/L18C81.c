#include "stdio.h"
#include "stdlib.h"
#include"string.h"


struct node
{
    int info;
    char name[200];
    struct node *lptr;
    struct node *rptr;
};

struct node *insert(struct node *, int,char []);
struct node *createNode(int,char []);
struct node *searchNode(struct node *, int);
struct node *delete(struct node *, int);
struct node *findDelete(struct node *);
void inorder(struct node *root);
void revinorder(struct node *root);

int main()
{
    int choice, value, x, a;
    char name[100];
    struct node *root = NULL;

    while (1)
    {
        printf("1 To Insert\n2 To Delete \n3 To Search\n4 To Ascending\n5 To Descending\n6 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Node Value : ");
            scanf("%d", &value);
              printf("Enter Name : ");
            scanf("%s",&name);
            root = insert(root, value,name);
            break;
        case 2:
            printf("Enter To Delete : ");
            scanf("%d", &a);
            delete(root, a);
            break;
        case 3:
            printf("Enter Node To Search : ");
            scanf("%d", &x);
            searchNode(root, x);
            break;
            case 4:
            printf("---Printing In Ascending Order---\n");
           revinorder(root);
            printf("NULL\n");
            break;
            case 5:
            printf("---Printing In Descending Order---\n");
            inorder(root);
            printf("NULL\n");
            break;
            case 6:
            printf("Exiting");
            return 0;
        }
    }
}




struct node *createNode(int value,char name[])
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    strcpy(newNode->name,name);
    newNode->lptr = newNode->rptr = NULL;
    return newNode;
}

struct node *insert(struct node *root, int value,char name[])
{
    if (root == NULL)
    {
        root = createNode(value,name);
    }
    if (strcmp(root->name,name) > 0)
    {
        root->rptr = insert(root->rptr, value,name);
    }
    else if (strcmp(root->name,name) < 0)
    {
        root->lptr = insert(root->lptr, value,name);
    }
    return root;
    // printf("Main : %d",root->info);
}


struct node *searchNode(struct node *root, int x)
{

    if (root == NULL)
    {
        printf("Not Found\n");
        return NULL;
    }
    if (x == root->info)
    {
        printf("%d %s Found\n", root->info,root->name);
        return root;
    }
    if (x > root->info)
    {
        // printf("%d to find - %d\n", root->info,x);
        return searchNode(root->rptr, x);
    }
    else if (x < root->info)
    {
        // printf("%d to find - %d\n", root->info,x);
        return searchNode(root->lptr, x);
    }
}

struct node *delete(struct node *root, int x)
{
    struct node *temp;
    if (root == NULL)
    {
        return NULL;
    }
    if (x == root->info)
    {
        if (root->rptr == NULL)
        {
            temp = root->lptr;
            printf("To delete : %d", root->info);
            free(root);
            return temp;
        }
        else if (root->lptr == NULL)
        {
            temp = root->rptr;
            printf("To delete : %d", root->info);
            free(root);
            return temp;
        }
        else if (root->lptr != NULL && root->rptr != NULL)
        {
            struct node *save = findDelete(root->rptr);
             root->info = save->info;
            root->rptr = delete(root->rptr, save->info);

        }
    }
   else if (x > root->info)
    {
        root->rptr = delete(root->rptr, x);
    }
    else if (x < root->info)
    {
        root->lptr = delete(root->lptr, x);
    }
    return root;
}

struct node *findDelete(struct node *root)
{
     while (root->lptr != NULL)
            {
                root = root->lptr;
            }
            return root;
           
}



void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lptr);
    printf("-->%d %s\n", root->info,root->name);
    inorder(root->rptr);
}

void revinorder(struct node *root)
{
     if (root == NULL)
    {
        return;
    }
    revinorder(root->rptr);
     printf("-->%d %s\n", root->info ,root->name);
     revinorder(root->lptr);
}