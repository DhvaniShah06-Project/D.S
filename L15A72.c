#include <stdio.h>
#include <stdlib.h>
struct node *insertFirst(struct node *lptr, struct node *);
void *insertEnd(struct node **lptr, struct node **);
void display(struct node *lptr, struct node *rptr);
void delElement(struct node **lptr, struct node **rptr);

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

int main()
{
    int choice;
    struct node *lptr = NULL;
    struct node *rptr = NULL;
    while (1)
    {
        printf("1 to insert at First\n2 To insert at end\n3 To Display\n4 To Delete\n5 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            lptr = insertFirst(lptr, rptr);
            break;
        case 2:
         insertEnd(&lptr, &rptr);
            break;
        case 3:
            printf("---Displaying Elements---\n");
            display(lptr, rptr);
            break;
        case 4:
            delElement(&lptr, &rptr);
            break;
        case 5:
            printf("---Exiting---\n");
            return 0;
        }
    }

    return 0;
}

struct node *insertFirst(struct node *lptr, struct node *rptr)
{
    int x;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value : ");
    scanf("%d", &x);
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = lptr;
    if (lptr != NULL)
    {
        lptr->lptr = newNode;
    }
    lptr = newNode;
    return lptr;
}

void *insertEnd(struct node **lptr, struct node **rptr)
{
    int x;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value : ");
    scanf("%d", &x);
    newNode->info = x;
    newNode->rptr = NULL;

    if (*lptr == NULL)
    {
        newNode->lptr=NULL;
        newNode->rptr = NULL;
        *lptr = *rptr = newNode;
    }

    else
    {
       (*rptr)->rptr = newNode;
        newNode->lptr = *rptr;
        *rptr = newNode;
    }
}

void display(struct node *lptr, struct node *rptr)
{
    struct node *save = lptr;
    if (save == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (save != NULL)
    {
        printf("%d->", save->info);
        save = save->rptr;
    }
    printf("NULL\n");
}

void delElement(struct node **lptr, struct node **rptr)
{
    struct node *save = *lptr;
    int value;
    printf("Enter Element to Delete : ");
    scanf("%d", &value);
    if (*lptr == *rptr)
    {
        free(*lptr);
        *lptr = *rptr = NULL;
    }
    else if (value == save->info)
    {
        struct node *temp = save;
        printf("First Deleted %d\n", temp->info);
        *lptr = save->rptr;
        free(temp);
    }
    else if (value == (*rptr)->info)
    {
        struct node *temp = *rptr;
        *rptr = (*rptr)->lptr;
        if (*rptr)
            (*rptr)->rptr = NULL;
        free(temp);
        return;
    }
    else
    {
        while (save != NULL && save->info != value)
        {
            save = save->rptr;
        }
        if (save==NULL)
        {
            printf("Element not Found\n");
            return;
        }
        save->lptr->rptr = save->rptr;
        save->rptr->lptr = save->lptr;
        free(save);
    }
}