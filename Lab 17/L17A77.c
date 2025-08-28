#include "stdio.h"
#include"stdlib.h"

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
int checkTree(struct node *,struct  node *);
struct node *constructTree();
int main()
{
    int a;
    struct node *root = NULL;
  root =  constructTree();
  a= checkTree(root->lptr, root->rptr);
  if(a==1)
  {
    printf("Symmetric\n");
  }
    
}

struct node *constructTree()
{
    // struct node *n1 = (struct node *)malloc(sizeof(struct node));
     struct node *root = (struct node *)malloc(sizeof(struct node));

    root->info = 8;

    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    n2->info = 5;
  root->lptr = n2;

    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    n3->info = 3;
    n2->lptr = n3;
    n3->rptr = NULL;
    n3->lptr = NULL;
    
    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    n4->info = 6;
    n2->rptr = n4;
    n4->rptr = NULL;
    n4->lptr = NULL;

    struct node *n5 = (struct node *)malloc(sizeof(struct node));
    n5->info = 5;
 root->rptr = n5;

    struct node *n6 = (struct node *)malloc(sizeof(struct node));
    n6->info = 6;
    n6->rptr = NULL;
    n6->lptr = NULL;
    n5->lptr = n6;

    struct node *n7 = (struct node *)malloc(sizeof(struct node));
    n7->info = 3;
    n5->rptr = n7;
    return root;
}

int checkTree(struct node *root1,struct node *root2)
{
    struct node *temp1 =root1;
    struct node *temp2 = root2;

    if(temp1==NULL&&temp2==NULL)
    {
        return 1;
    }

    if(temp1->info != temp2->info)
    {
        printf("Not Symmetric\n");
        return 0;
    }
    else if(temp1->lptr !=NULL && temp1->rptr!=NULL && temp2->lptr!=NULL && temp2->rptr!=NULL)
    if(temp1->info == temp2->info){
        checkTree(temp1->lptr,temp2->rptr);
        checkTree(temp1->rptr,temp2->lptr);
        return 1;
       
    }
}