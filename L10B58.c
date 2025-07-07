#include <stdio.h>
#include <stdlib.h>

struct node *enterElement(struct node *list);
void display(void *list, void *list2);

struct node
{
    int info;
    struct node *link; // self defined structurial
};
int main()
{
    struct node *first = NULL;
    struct node *begin = NULL;
    int choice, a;
    while (1)
    {
        printf("Enter Choice For Entering Element\n1 For 1st List\n2 for 2nd List\n3 For Exit\n4 For display Result Or Comparing\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = enterElement(first);
            break;
        case 2:
            begin = enterElement(begin);
            break;
        case 3:
            printf("Exiting ....");
            return 0;
        case 4:
            display(first, begin);
            break;
        }
    }
}
struct node *enterElement(struct node *list)
{
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = NULL;
    struct node *save;

    if (list == NULL)
    {
        return newNode;
    }

    else
    {
        save = list;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }
    return list;
}
void display(void *list, void *list2)
{
    int flag = 1;
    struct node *temp = (struct node *)list;
    struct node *comp = (struct node *)list2;

    while (temp != NULL && comp !=NULL)
    {
        if (temp->info != comp->info)
        {
            flag = 0;
            break;
        }
        temp = temp->link;
        comp = comp->link;
    } 
    if (comp == NULL && temp == NULL)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    if (flag == 0)
    {
        printf("Lists Are Not Same\n");
    }
    else
    {
        printf("Both Lists Are Same\n");
    }
}
