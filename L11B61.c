#include <stdio.h>
#include <stdlib.h>
void enqueue();
void display();
void isEmpty();
void peek();
void dequeue();
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;

int main()
{
    int choice;
    while (1)
    {
        printf("1 To Insert In Queue\n2 To Remove Top Most And Display It\n3 To Just Top Most Peek\n4 To Check If Is empty or not\n5 To Display And Count Elements\n6 To Exit\n");
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
            peek();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("---Exiting---");
            return 0;
        }
    }
    return 0;
}
void enqueue()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter Value : ");
    scanf("%d", &value);
    newNode->info = value;
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
    if (first == NULL)
    {
        printf("empty Queue\n");
        return;
    }
    struct node *temp = first;
    printf("Removed Top Most Element : %d\n", first->info);
    first = first->link;
    free(temp);
}
void peek()
{
    if (first == NULL)
    {
        printf("Empty\n");
        return;
    }
    printf("Top Most Element : %d\n", first->info);
}
void isEmpty()
{
    if (first == NULL)
    {
        printf("Yes Empty\n");
        return;
    }
    printf("No Not Empty\n");
}
void display()
{
    int count = 0;
    struct node *temp = first;
    if (first == NULL)
    {
        printf("Empty Queue\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d --> ", temp->info);
        count++;
        temp = temp->link;
    }
    printf("\n Size : %d\n", count);
}