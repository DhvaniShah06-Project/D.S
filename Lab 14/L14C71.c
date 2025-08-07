#include <stdio.h>
#include <stdlib.h>
struct node *insEnd(struct node *first);
void display();
struct node *add(struct node *first, struct node *begin);
struct node
{
    int coeff;
    int pow;
    struct node *link;
};
struct node *last = NULL;

int main()
{
    struct node *first = NULL;
    struct node *begin = NULL;

    int choice, ans;
    while (1)
    {
        printf("1 To insert first polynomial\n2 To insert Second polunomial\n3 to display first polynomial\n4 to display second polynomial\n5 to Add\n6 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insEnd(first);
            break;
        case 2:
            begin = insEnd(begin);
            break;
        case 3:
            printf("First\n");
            display(first);
            break;
        case 4:
            printf("Second\n");
            display(begin);
            break;
        case 5:
            add(first, begin);
            break;
        case 6:
            printf("---Exiting---");
            return 0;
        }
    }
}

struct node *insEnd(struct node *first)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    int x, pow;
    printf("Enter Value : ");
    scanf("%d", &x);
    printf("Enter power : ");
    scanf("%d", &pow);
    new->coeff = x;
    new->pow = pow;
    if (first == NULL)
    {
        new->link = new;
        first = last = new;
        return first;
    }
    new->link = first;
    last->link = new;
    last = new;
    return first;
}

void display(struct node *first)
{
    if (first == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *save = first;
    do
    {
        printf("%dx^%d +", save->coeff, save->pow);
        save = save->link;
    } while (save != first);
    printf("Head");
    printf("\n");
}

struct node *add(struct node *first, struct node *begin)
{
    struct node *temp1 = first;
    struct node *temp2 = begin;
    struct node *new = (struct node *)malloc(sizeof(struct node));

    do
    {

        if (temp1->pow == temp2->pow)
        {
            new->pow = temp1->pow;
            new->coeff = temp1->coeff + temp2->coeff;
            printf("%d^%d+", new->coeff, new->pow);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else if (temp1->pow > temp2->pow)
        {
            new->pow = temp1->pow;
            new->coeff = temp1->coeff;
            printf("%d^%d+", new->coeff, new->pow);

            temp1 = temp1->link;
        }

        else
        {
            new->pow = temp2->pow;
            new->coeff = temp2->coeff;
            printf("%d^%d+", new->coeff, new->pow);
            temp2 = temp2->link;
        }

    } while (temp1 != first && temp2 != begin);
}
