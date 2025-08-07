// if return then first return so it's type is struct node and * for pointer
#include <stdio.h>
#include <stdlib.h>
void InsertFirst(int x);
void InsertEnd(int x);
void display();
void deleteFirst();
void deleteLast();
void deleteElement(int x);
struct node
{
    int info;
    struct node *link; // self defined structurial
};
struct node *first = NULL;
int main()
{
    int choice, a;
    while (1)
    {
        printf("1 To Insert At Start \n2 To Insert At End\n3 To Delete node From Start\n4 To Delete From End\n5 to Delete Any Element\n6 To Display Elements\n7 To Exit\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element To be Inserted At First : ");
            scanf("%d", &a);
            InsertFirst(a);
            break;
        case 2:
            printf("Enter Element To be Inserted At End : ");
            scanf("%d", &a);
            InsertEnd(a);
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            printf("Enter Element To Delete : ");
            scanf("%d", &a);
            deleteElement(a);
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exiting ..");
            return 0;
        }
    }
}
void InsertFirst(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}
void InsertEnd(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    struct node *save;
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
void deleteFirst()
{
    if (first == NULL)
    {
        printf("List Is empty Cannot be deleted\n");
        return;
    }
    first = first->link;
}
void deleteLast()
{
    if (first == NULL)
    {
        printf("List Is empty Cannot be deleted\n");
        return;
    }
    struct node *save = first;
    struct node *pre = save;
    while (save->link != NULL)
    {
        pre = save;
        save = save->link;
    }
    pre->link = NULL;
}

void deleteElement(int x)
{
    struct node *save = first;
    struct node *pre = save;
    while (save->link != NULL && save->info != x)
    {
        pre = save;
        save = save->link;
    }
    if (x != save->info)
    {
        printf("Element To Delete is not in List\n");
        return;
    }
    else
    {
        if (x == first->info)
        {
            first = first->link;
        }
        else
        {
            pre->link = save->link;
        }
        free(save);
    }
}

void display()
{
    struct node *current = first;
    int count = 0;
    if (current == NULL)
    {
        printf("Empty List");
        return;
    }
    else
    {
        printf("------Displaying Elements------\n");
        while (current != NULL)
        {
            printf("  |%d | -->", current->info);
            count++;
            current = current->link;
        }
    }
    printf("\n");
    printf("\nTotal Elements In List : %d\n", count);
}