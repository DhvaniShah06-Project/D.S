#include <stdio.h>
#include <stdlib.h>

struct node *insert(struct node *, int);
struct node *createNode(int);
void inorder(struct node *root);
void preOrder(struct node *root);
void postOrder(struct node *root);
struct node *searchNode(struct node *, int);
struct node *delete(struct node *, int);
struct node *findDelete(struct node *);

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
int main()
{
    int choice, value, x, a;
    struct node *root = NULL;

    while (1)
    {
        printf("\n1 To Insert\n2 To Delete \n3 To Search\n4 To preorder Travesal\n5 To PostOrder Traversal\n6 To Inorder Travaersal\n7 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Node Value : ");
            scanf("%d", &value);
            root = insert(root, value);
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
            preOrder(root);
            break;
        case 5:
            postOrder(root);
            break;
        case 6:
            inorder(root);
            break;
        case 7:
            printf("Exiting");
            return 0;
        }
    }
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
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lptr);
    printf("%d-->", root->info);
    inorder(root->rptr);
}

void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d-->", root->info);
    preOrder(root->lptr);
    preOrder(root->rptr);
}

void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->lptr);
    preOrder(root->rptr);
    printf("%d-->", root->info);
}

struct node *searchNode(struct node *root, int x)
{

    if (root == NULL)
    {
        printf("Not Found\n");
        return 0;
    }
    if (x == root->info)
    {
        printf("%d Found\n", root->info);
    }
    if (x > root->info)
    {
        return searchNode(root->rptr, x);
    }
    else if (x < root->info)
    {
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
            // while (save->lptr != NULL)
            // {
            //     save = save->lptr;
            // }
            // root->info = save->info;
            // root->rptr = delete(root->rptr, save->info);
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