// circular link list into half
#include <stdio.h>
#include <stdlib.h>
struct node *insEnd(struct node *first);
int display(struct node *first);
void Split(struct node *first, int);
struct node
{
    int info;
    struct node *link;
};
struct node *last = NULL;
int main()
{
    struct node *first = NULL;

    int choice, num;
    while (1)
    {
        printf("1 To Insert at End\n2 To Display\n3 To Split\n4 to Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insEnd(first);
            break;
        case 2:
            num = display(first);
            break;
        case 3:
            Split(first, num);
            break;
        case 4:
            printf("---Exiting---");
            return 0;
        default:
            printf("Please Enter Valid Choice\n");
            break;
        }
    }
    return 0;
}
struct node *insEnd(struct node *first)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter Value : ");
    scanf("%d", &x);
    new->info = x;
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

int display(struct node *first)
{
    struct node *temp = first;
    int count = 0, num;
    if (first == NULL)
    {
        printf("Empty List\n");
        return 0;
    }
   
    do
    {
        printf("%d-->", temp->info);
        count++;
        
        temp = temp->link;
    } while (temp != first);
    printf("%d ",temp->info);
    printf("\n");
    return count;
}
void Split(struct node *first, int num)
{
    struct node *temp = first;
    struct node *last1 = last;
    struct node *last2 = last;
    struct node *pre = NULL;
    int count = 0;

    printf("---List 1---\n");
    if(num % 2 ==0)
    {
        num = num/2;
    }
    else{
        num = num/2 + 1;
    }
    printf("Num : %d\n",num);
    while (count < num)
    {
        // printf("%d ->", temp->info);
        pre = temp;
        temp = temp->link;
        count++;
    }
    printf("\n");
    // printf("\n%d\n",temp->link->info);
    struct node *save = temp;
    struct node *first2 = save;
    pre->link = first;
    last1 = pre;
    last2->link = first2;
    display(first);
    printf("\nFirst %d Last1 %d First 2 : %d Last2 : %d\n", first->info, last1->info, first2->info, last2->info);
    printf("\n---List 2---\n");
    // do
    // {
    //     printf("%d->",save->info);
    //     save = save->link;
    // }while(save!=first2);
    // printf("\n");
    display(first2);
}