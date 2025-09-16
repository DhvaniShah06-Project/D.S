#include "stdio.h"
#include "stdlib.h"
#define RED 0
#define BLACK 1

typedef struct node
{
    int data;
    int color;
    struct node *left, *right, *parent;
} node;
void insert(int);
void fixInsert(struct node *);
void leftRotate(struct node *x);
void rightRotate(struct node *y);
void inorder(struct node *);
struct node *createNode(int);

struct node *root = NULL;

int main()
{
    int nums[] = {10, 25, 35, 1, 40,20};
    int n = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < n; i++)
    {
        insert(nums[i]);
    }
    inorder(root);
    return 0;
}

struct node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void insert(int data)
{
    node *node = createNode(data);
  struct node *y = NULL;
  struct node *x = root;
    while (x != NULL)
    {
        y = x;
        if (node->data < x->data)
        {
            x = x->left;
        }
        else
            x = x->right;
    }
    node->parent = y;
    if (!y)
        root = node;
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;

    fixInsert(node);
}

void fixInsert(struct node *k)
{
    node *uncle;
    while (k != root && k->parent->color == RED)
    {
        if (k->parent == k->parent->parent->left)
        {
            uncle = k->parent->parent->right;
            if (uncle && uncle->color == RED)
            {
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->right)
                {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }
        else
        {
            uncle = k->parent->parent->left;
            if (uncle && uncle->color == RED)
            {
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->left)
                {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        }
    }
    root->color = BLACK;
}
void leftRotate(struct node *x)
{
    node *y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(node *y)
{
    node *x = y->left;
    y->left = x->right;
    if (x->right)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (!y->parent)
    {
        root = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }
    x->left = y;
    y->parent = x;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d(%s) --> ", root->data, root->color == RED ? "R" : "B");
    inorder(root->right);
}