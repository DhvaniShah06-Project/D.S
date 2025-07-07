#include <stdio.h>
#include <stdlib.h>
struct node *insEnd(struct node *first);
void display(struct node *first);
struct node *swap(struct node *first);

struct node
{
    int info;
    struct node *link;
};

int main()
{
    int choice;
    struct node *first = NULL;
    while (1)
    {
        printf("1 To insert Element\n2 To Swap\n3 To Display\n4 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insEnd(first);
            break;
        case 2:
           first=swap(first);
            break;
        case 3:
            display(first);
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
    struct node *save = first;
    int x;
    printf("Enter value : ");
    scanf("%d", &x);
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        return newNode;
    }
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newNode;
    return first;
}

void display(struct node *first)
{
    struct node *temp = first;
    if (first == NULL)
    {
        printf("Empty List \n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}
struct node *swap(struct node *first)
{
    struct node *prev = NULL;
    struct node *curr = first;

    first = curr->link; // New head after first swap

    while (curr != NULL && curr->link != NULL)
    {
        struct node *next = curr->link;
        struct node *nextPair = next->link;

        // Swap
        next->link = curr;
        curr->link = nextPair;

        if (prev != NULL)
            prev->link = next;

        // Move pointers forward
        prev = curr;
        curr = nextPair;
    }
    return first;
}