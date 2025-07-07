#include <stdio.h>
#include <stdlib.h>
struct node *insEnd(struct node *first);
int display(struct node *first);
void swapDisplay(struct node *answer);
struct node *swap(int, struct node *first);
struct node
{
    int info;
    struct node *link;
};
int main()
{
    struct node *first = NULL;
    struct node *answer = NULL;
    int choice, ans;
    while (1)
    {
        printf("1 To Insert End\n2 To Display\n3 To Swap\n4 To Display Swap List\n5 To Exit\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insEnd(first);
            break;
        case 2:
            ans = display(first);
            break;
        case 3:
            answer = swap(ans, first);
            break;
        case 4:
            swapDisplay(answer);
            break;
        case 5:
            printf("---Exiting---");
            return 0;
        }
    }
    return 0;
}
struct node *insEnd(struct node *first)
{
    int value;
    printf("Enter value : ");
    scanf("%d", &value);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = NULL;
    if (first == NULL)
    {
        return newNode;
    }
    struct node *save = first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newNode;
    return first;
}

int display(struct node *first)
{
    struct node *save = first;
    int count = 0;
    while (save != NULL)
    {
        printf("%d-->", save->info);
        count++;
        save = save->link;
    }
    printf("NULL\n");
    printf("Count %d\n", count);
    return count;
}

struct node *swap(int ans, struct node *first)
{
    int k, i = 1, j = 1;
    printf("Enter k : ");
    scanf("%d", &k);
    if (first == NULL || first->link == NULL)
    {
        printf("Insufficient nodes to swap.\n");
        return first;
    }
    if (k <= 0 || k > ans)
    {
        printf("Invalid k value.\n");
        return first;
    }

    struct node *curr = first;
    struct node *pre = NULL;
    struct node *move = first;
    struct node *previ = NULL;
    for (; i < k; i++)
    {
        pre = curr;
        curr = curr->link;
    }

    for (j = 1; j < (ans - k + 1); j++)
    {
        previ = move;
        move = move->link;
    }
    if (curr == move)
    {
        printf("No Swap Needed\n");
        return first;
    }
    struct node *temp = curr->link;

    pre->link = move;
    previ->link = curr;
    curr->link = move->link;
    move->link = temp;
    printf("%d %d\n", pre->info, previ->info);

    printf("End: %d\n", curr->info);
    printf("Begg : %d\n", move->info);
    return first;
}
void swapDisplay(struct node *first)
{
    struct node *temp = first;
    if (temp == NULL)
    {
        printf("Empty List");
        return;
    }
    while (temp != NULL)
    {
        printf("%d-->", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}