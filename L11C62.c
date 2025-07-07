#include <stdio.h>
#include <stdlib.h>
void insertEnd();
void display();
void removeDuplicate();
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;

int main()
{
    int choice, a;
    while (1)
    {
        printf("1 To Insert At End\n2 To Sort List\n3 To Display Elements\n4 To Exit\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        insertEnd();
        break;
        case 2: 
        removeDuplicate();
        break;
        case 3 :
        display();
        break;
        case 4:
        printf("---Exiting---");
        return 0;
        }

    }
    return 0;
    }

void insertEnd()
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
void removeDuplicate()
{
    struct node *s1 = first;
    int count = 1, dup;
    while (s1!=NULL && s1->link != NULL)
    {
        struct node *pre = s1;
        struct node *s2 = s1->link;

        while (s2 != NULL)
        {
            if (s1->info == s2->info)
            {
                pre->link = s2->link;
                 struct node *temp = s2;
                count++;
                dup = s2->info;
                s2 = pre->link;
                free(temp);
            }
            else
            {
                pre = s2;
                s2 = s2->link;
            }
        }
        printf("%d is duplicate %d times\n",dup,count);
        count = 1;
        s1 = s1->link;
    }
}

void display()
{
    struct node *temp = first;
    if (first == NULL)
    {
        printf("Empty List");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}