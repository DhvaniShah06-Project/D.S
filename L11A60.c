#include "stdio.h"
#include "stdlib.h"
struct node *push(struct node *list);
void pop();
struct node *peek();
void display();
void clear();

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
int main()
{
    int choice;
    printf("Implementing Stack : \n");
    while (1)
    {
        printf("1 To Push(Add Element)\n2 To Pop(Remove Top Most Element)\n3 To Peek(Return value of topmost)\n4 To display Stack\n5 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = push(first);
            break;
        case 2:
            pop();
            break;
        case 3:
            first = peek();
            if (first == NULL)
            {
                printf("Empty Stack");
            }
            else
            {

                printf("Returning First Element : %d \n", first->info);
            }
            break;
        case 4:
            display();
            break;
        case 5:
        clear();
            printf("---Exiting---");
            return 0;
        }
    }

    return 0;
}
struct node *push(struct node *list)
{
    int value;
    printf("Enter Stack Element : ");
    scanf("%d", &value);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = first;
    first = newNode;
    return newNode;
}

void pop()
{
    if (first == NULL)
    {
        printf("Empty Stack\n");
        return;
    }
    printf("Successfully Deleted First Element Value Is :  %d\n", first->info);
    struct node *temp =first;
    first = first->link;
    free(temp);
}
struct node *peek()
{
    if (first == NULL)
    {
        printf("Empty Stack\n");
        return NULL;
    }
    return first;
}
void display()
{
    struct node *current = first;
    if (current == NULL)
    {
        printf("Empty Stack\n");
        return;
    }
    printf("---Displaying Element---\n");
    while (current != NULL)
    {
        printf("%d\n", current->info);
        current = current->link;
    }
}
void clear() {
    struct node *save = first;
    struct node *temp;
    printf("\nClearing all stack elements...\n");
    while (save != NULL) {
        temp = save;
        save = save->link;
        free(temp);
    }
    first = NULL;
}
