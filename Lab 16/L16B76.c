 #include "stdio.h"
 #include <stdlib.h>

struct node *createNode(int);
void insert(struct node* root);
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
    int choice,value,val1,val2;
    printf("Enter Root 1 And Root 2 : ");
    scanf("%d %d",&val1,&val2);
    root1 = createNode(val1);
    root2 = createNode(val2);
    while(1)
    {
        printf("1 To Insert in Tree 1\n2 To Insert in Tree 2\n3 To Display Tree 1(In Order)\n4 To Display Tree 2(In Order)\n5 To Compare\n6 To Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
          insert(root1);
            break;
            case 2:
            insert(root2);
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
           else{
            printf("Not Same\n");
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



struct node* search(struct node* root, int value) {
    if (root == NULL) return NULL;
    if (root->info == value) return root;

    struct node* found = search(root->lptr, value);
    if (found != NULL) return found;

    return search(root->rptr, value);
}


void insert(struct node* root) {
    int parentValue, newValue, choice;
    printf("\nEnter parent node value: ");
    scanf("%d", &parentValue);

    struct node* parent = search(root, parentValue);
    if (parent == NULL) {
        printf("Parent not found!\n");
        return;
    }

    printf("Enter new node value: ");
    scanf("%d", &newValue);

    printf("Insert as (1) Left child or (2) Right child? ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (parent->lptr == NULL) {
            parent->lptr = createNode(newValue);
        } else {
            printf("Left child already exists!\n");
        }
    } else if (choice == 2) {
        if (parent->rptr == NULL) {
            parent->rptr = createNode(newValue);
        } else {
            printf("Right child already exists!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }
   
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
    printf("%d %d\n",root1->info,root2->info);
    if(root1==NULL || root2==NULL)
    {
        return 0;
    }

    if( root1->lptr==NULL&&root2->lptr!=NULL || root1->rptr==NULL&&root2->rptr!=NULL || root1->info != root2->info)
    {
        return 1;
    }
    else if(root1->info == root2->info && compare(root1->lptr,root2->lptr) &&  compare(root1->rptr,root2->rptr)){
        return 0;
    }
    // printf("%d-->", root->info);
}