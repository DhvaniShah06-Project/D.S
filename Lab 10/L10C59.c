#include "stdio.h"
#include "stdlib.h"
void insertElement(int x);
void compare();
void displayElement();
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
int main()
{
    int a, choice;
    while (1)
    {
        printf("\n1 to Insert\n2 To Compare List\n3 For Displaying Final List\n4 For Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element :");
            scanf("%d", &a);
            insertElement(a);
            break;
        case 2:
            compare();
            break;
        case 3:
            printf("------Displaying Distinct------\n");
            displayElement();
            break;
        case 4:
            printf("---Exiting---");
            return 0;
        }
    }

    return 0;
}

void insertElement(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *save;
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        first = newNode;
        return;
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
}
void compare()
{
    struct node *temp;
    temp = first;
    if (first == NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
        while (temp != NULL && temp->link != NULL)
        {
            if (temp->info == temp->link->info)
            {
                temp->link = temp->link->link;
            }
            else{
            temp = temp->link;

            }
        }
    }
    /*currrent-info = info of link of current*/
}
void displayElement()
{
    struct node *current = first;
    if (first == NULL)
    {
        printf("Empty List");
        return;
    }

    while (current != NULL)
    {
        printf("|%d|-->", current->info);
        current = current->link;

    }
}