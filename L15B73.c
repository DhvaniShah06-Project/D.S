#include <stdio.h>
#include <stdlib.h>
struct node *insEnd(struct node *);
void display(struct node *);
void delete(struct node *);

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *first = NULL;

int main()
{
    struct node *lptr = NULL;
    struct node *rptr = NULL;
    int choice, ans;
    while (1)
    {
        printf("1 to insert at end\n2 To display\n3 to delete\n4 To exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insEnd(first);
            break;
        case 2:
            display(first);
            break;
        case 3:
            delete(first);
            break;
        case 4:
            printf("---Exiting---");
            return 0;
        }
    }

    return 0;
}
struct node *insEnd(struct node *first)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter value : ");
    scanf("%d", &x);
    newNode->info = x;
    // newNode->lptr = NULL;
    newNode->rptr = NULL;
    if (first == NULL)
    {
        printf("Here");

        newNode->lptr = NULL;
        newNode->rptr = NULL;
        first = newNode;
        return first;
    }
    struct node *temp = first;
    while (temp->rptr != NULL)
    {
        temp = temp->rptr;
    }
    // printf("%d",newNode->info);
    temp->rptr = newNode;
    newNode->lptr = temp;
    return first;
}
void display(struct node *first)
{
    struct node *save = first;
    if (save == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (save != NULL)
    {
        printf("%d-->", save->info);
        save = save->rptr;
    }
    printf("NULL\n");
}
void delete(struct node *first)
{
    struct node *temp = first->rptr;
    int count = 0;
    while (temp != NULL)
    {
        printf("Temp : %d\n", temp->info);
        struct node *save = temp;
        count++;
        temp = temp->rptr;
        if (count % 2 != 0)
        {
            printf("Delete Element : %d\n",save->info);
            save->lptr->rptr = save->rptr;
            save->rptr->lptr = save->lptr;
            free(save);
        }
    }
    display(first); 
}
