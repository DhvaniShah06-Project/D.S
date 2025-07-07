#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *enterElement(struct node *first);
void display(struct node *first);
struct node *copyList(struct node *first);

struct node *first = NULL;
int main()
{
    int choice;
    
    struct node *copied = NULL;
    while (1)
    {
        printf("1 To insert Element\n2 To Display\n3 To Copy\n4 To display copy\n5 To exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = enterElement(first);
            break;
        case 2:
            display(first);
            break;
        case 3:
            copied = copyList(first);
            break;
        case 4:
            display(copied);
            break;
        case 5:
            printf("---Exiting---");
            return 0;
        }
    }
    printf("Display\n");
    display(first);

    copyList(first);
    printf("Copied List");
    display(first);

    return 0;
}
struct node *enterElement(struct node *first)
{
    int value;
    printf("Enter Value : ");
    scanf("%d", &value);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = NULL;
    struct node *save;
    if (first == NULL)
    {
        return newNode;
    }

    else
    {
        save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }
    return first;
}
struct node *copyList(struct node *first)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *pre = NULL;
    newNode->info = first->info;
    struct node *begin= NULL;
    begin = newNode;
    struct node *save = first;
    while (save->link != NULL)
    {
        pre = newNode;
        save = save->link;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = save->info;
        pre->link = newNode;
    }
    newNode->link = NULL;
    return begin;
}
void display(struct node *first)
{
    struct node *temp = first;
    if (temp == NULL)
    {
        printf("Empty first");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -->", temp->info);
        ;
        temp = temp->link;
    }
    printf("NULL\n");
}