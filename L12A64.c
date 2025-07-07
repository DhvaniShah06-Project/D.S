#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *enterElement(struct node *first);
void display(struct node *first);
struct node *reverseList(struct node *first);
int main()
{
    int choice;
    struct node *first = NULL;
    struct node *answer = NULL;
    while (1)
    {
        printf("1 To insert\n2 To Display\n3 To reverse\n4 To Display Reverse List\n5 To exit\n");
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
            answer = reverseList(first);
            break;
        case 4:
            printf("---Displaying Reverse List---\n");
            display(answer);
            break;
        case 5:
            printf("---Exiting---");
            return 0;
        }
    }

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

struct node *reverseList(struct node *first)
{
    struct node *nextNode = NULL;
    struct node *preNode = NULL;
    struct node *currNode = first;
    while(currNode!= NULL)
    {
        nextNode = currNode->link;
        currNode->link = preNode;
        preNode = currNode;
        currNode = nextNode;
    }
    return preNode;
}

void display(struct node *first)
{
    struct node *temp = first;
    if (temp == NULL)
    {
        printf("Empty List");
        return;
    }
    while (temp != NULL)
    {
        printf("%d --> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
    return;
}
