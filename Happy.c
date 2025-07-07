#include <stdio.h>
#include <stdlib.h>
int findHappy();
void insEnd(int);
int checkNum(int);
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
int main()
{

    int value;
    printf("Enter Value :");
    scanf("%d", &value);
    findHappy(value);

    return 0;
}
int findHappy(int value)
{
    printf("\nCalled Find Happy Function\n");
    int rem, sum = 0;
    int temp = value;
    while (temp != 0)
    {
        rem = temp % 10;
        sum = sum + (rem * rem);
        temp = temp / 10;
    }
    printf("Sum : %d\n", sum);
    if (sum == 1)
    {
        printf("Happy Number");
        return 0;
    }
    int a = checkNum(sum);
    if (a == 1)
    {
        return 0;
    }
    insEnd(sum);
    findHappy(sum);
}
void insEnd(int sum)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = sum;
    printf("\nNode called to insert at start\n");
    new->link = NULL;

    if (first == NULL)
    {
        first = new;
        return;
    }

    struct node *save = first;
    printf("\n Node -> Info : %d\n", save->info);
    while (save->link!= NULL)
    {
        save = save->link;
    }
    save->link = new;
    printf("Return Number From Node : %d\n", sum);
    // findHappy(sum);
}
int checkNum(int sum)
{

    struct node *temp = first;
    while (temp != NULL)
    {
        if (temp->info == sum && temp->info != 1)
        {
            printf("Not Happy Number");
            return 1;
        }
        else
        {
            temp = temp->link;
        }
    }
}