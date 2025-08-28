#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
void inorder(struct node *);
struct node *createNode(int value);
struct node *constructbst(int post[], int pre[], int *preIdx, int size, int s, int e);
int searchNode(int post[], int k, int s, int e);

int main()
{
    struct node *root;
    int s = 0, size;
    int *preIdx = (int *)malloc(sizeof(int));
    *preIdx = 0;
    printf("Enter Size : ");
    scanf("%d", &size);
    int e = size - 1;
    int pre[size], post[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter Pre Order : ");
        scanf("%d", &pre[i]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter Post Order : ");
        scanf("%d", &post[i]);
    }
    root = constructbst(post, pre, preIdx, size, s, e);
    inorder(root);

    return 0;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lptr = newNode->rptr = NULL;
    return newNode;
}

struct node *constructbst(int post[], int pre[], int *preIdx, int size, int s, int e)
{
    if (*preIdx > size || s > e)
    {
        return NULL;
    }
    struct node *root = createNode(pre[*preIdx]);
    (*preIdx)++;
    if (s == e || *preIdx > size)
    {
        return root;
    }
    int k = pre[*preIdx];
    int i = searchNode(post, k, s, e);
    if (i != -1)
    {
        root->lptr = constructbst(post, pre, preIdx, size, s, i);
        root->rptr = constructbst(post, pre, preIdx, size, i + 1, e - 1);
    }
    return root;
}

int searchNode(int post[], int k, int s, int e)
{
    int j = s;
    for (; j <= e; j++)
    {
        if (k == post[j])
        {
            return j;
        }
    }
    if (k != post[j])
    {
        return -1;
    }
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