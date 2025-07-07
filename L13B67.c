#include <stdio.h>
#include <stdlib.h>

int findGCD(int, int);
struct node *enterElement(struct node *);
void display(struct node *first);
void normalDisplay(struct node *first);

struct node
{
    int info;
    struct node *link;
};
int main()
{
    struct node *first = NULL;
    int choice;
    while (1)
    {
        printf("1 To insert Element\n2 to Display\n3 To  GCD\n4 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = enterElement(first);
            break;
        case 2:
            normalDisplay(first);
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

void display(struct node *first)
{

    struct node *save = first;
    int answer;

    while (save->link != NULL)
    {
        if (save == NULL)
        {
            printf("Empty\n");
            return;
        }
        answer = findGCD(save->info, save->link->info);
        printf("GCD : %d\n", answer);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = answer;
        newNode->link = save->link;
        save->link = newNode;
        save = newNode->link;
    }
}

void normalDisplay(struct node *first)
{
    struct node *temp = first;
    if (temp == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d --> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}
int findGCD(int a, int b)
{
    int i, gcd, min = (a > b) ? (b) : (a);
    for (i = 1; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}