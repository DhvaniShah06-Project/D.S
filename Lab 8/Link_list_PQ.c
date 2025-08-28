#include "stdio.h"

#include "stdlib.h"

struct node
{
    int data;
    int priority;
    struct node *link;
};
struct node *first = NULL;
void enqueue();
void dequeue();
void display();
int main()
{

    int choice;
    while (1)
    {

        printf("1 To Enqueue\n2 To Dequeue\n3 To Display\n4 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting");
            return 0;

        default:
            printf("Enter Valid Choice\n");
            break;
        }
    }

    return 0;
}

void enqueue()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int value, priority;
    printf("Enter Value and Priority: ");
    scanf("%d %d", &value, &priority);

    newNode->data = value;
    newNode->priority = priority;
    newNode->link = NULL;
    struct node *save = first;
    if (first == NULL)
    {
        first = newNode;
        return;
    }
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newNode;
}

void dequeue()
{
    struct node *save = first;
    struct node *temp = first;
    struct node *pre = NULL;
    while (temp != NULL)
    {
       
        if (save->priority < temp->priority)
        {
            pre = save;
            save = temp;
           
        }
        temp = temp->link;
    }
    pre->link = save->link;
    printf("Dequeued Element : %d | %d\n", save->data, save->priority);
    free(save);
   
}

void display()
{
    int i;
    struct node *temp = first;
    if (temp == NULL)
    {
        printf("Empty");
        return;
    }
    printf("-----Displaying Queue-----\n");
    while (temp != NULL)
    {
        printf("%d|%d-->", temp->data, temp->priority);
        temp = temp->link;
    }

    printf("END\n");
}