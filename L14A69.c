#include <stdio.h>
#include <stdlib.h>
struct node *insertStart(struct node *first);
struct node *insertEnd(struct node *first);
void display(struct node *first);
struct node *deleteElement(struct node *first);
struct node
{
    int info;
    struct node *link;
};
struct node *last = NULL;
int main()
{
    struct node *first = NULL;

    int choice;
    while (1)
    {
        printf("1 To Insert at start\n2 To Delete from a position\n3 to Insert at End\n4 to Display\n5 to Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insertStart(first);
            break;
        case 2:
            first = deleteElement(first);
            break;
        case 3:
            first = insertEnd(first);
            break;
        case 4:
            printf("---Displaying Elements---\n");
            display(first);
            break;
        case 5:
            printf("---Exiting---");
            return 0;
        default:
            printf("Please Enter valid choice");
        }
    }

    return 0;
}

struct node *insertStart(struct node *first)
{
    int value;
    printf("Enter value : ");
    scanf("%d", &value);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    if (first == NULL)
    {
        newNode->link = newNode;
        first = last = newNode;
        return first;
    }

    newNode->link = first;
    last->link = newNode;
    first = newNode;
    return first;
}
struct node *deleteElement(struct node *first)
{
    if (first == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    int value;
    printf("Enter Element To delete : ");
    scanf("%d", &value);
    struct node *save = first;
    struct node *pre;

    while (save->info != value && save != last)
    {
        pre = save;
        save = save->link;
    }

    if (value != save->info)
    {
        printf("Element To Delete is not in List\n");
        return first;
    }
if (first == last) {
    printf("Deleting last remaining node: %d\n", save->info);
    free(save);
    first = last = NULL; // RESET both to avoid dangling pointers
    return first;
}

  if(save == first){
     printf("First\n");
    printf("Element To delete : %d\n",save->info);
    struct node *temp = first;
    first = first->link;
    last->link = first;
    printf("Deleted First Node: %d\n", temp->info);
    free(temp);
    return first;
}

    if(save == last){
        printf("Last\n");
        struct node *temp = last;
        printf("%d\n",temp->info);
        last = pre;
        last->link = first;
        printf("Last Node deleted %d\n",temp->info);
        free(temp);
        return first;
    
    }


    if(save!= first && save!=last)
    {
        printf("Normal Element To delete : %d\n",save->info);
        printf("Delete Element\n");
        pre->link = save->link;
        free(save);
        return first;
    }
}
struct node *insertEnd(struct node *first)
{
    int value;
    printf("Enter value : ");
    scanf("%d", &value);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    struct node *save = first;
    if (first == NULL)
    {
        newNode->link = newNode;
        first = last = newNode;
        return first;
    }

    newNode->link = first;
    last->link = newNode;
    last = newNode;
    return first;
}
void display(struct node *first)

{

    if (first == NULL)
    {
        printf("Empty\n");
        return;
    }
    // if (first == last)
    // {
    //     printf("%d\n", first->info);
    //     return;
    // }
    struct node *save = first;
    do
    {
        printf("%d-->", save->info);
        save = save->link;
    } while (save != first);
    printf("Head");
    printf("\n");
}