#include <stdio.h>
#include <stdlib.h>
struct node *enterElement(struct node *list);
void display();
void sort();
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
struct node *begin = NULL;
int main()
{
    int choice, a;
    while (1)
    {
        printf("Enter Choice For Entering Element\n1 For 1st List\n2 For Exit\n3 For display Result\n4 To Sort\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
           first =  enterElement(first);
            break;
        case 2:
            printf("Exiting ....");
            return 0;
        case 3:
            display();
            break;
            case 4:
            sort();
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

void display(){
    struct node *temp = first;
    if(first == NULL){
        printf("Empty");
        return;
    }
    while(temp!=NULL){
        printf("%d--> ",temp->info);
        temp = temp->link;
    }
    printf("\n");
}
void sort(){
     struct node *i, *j;
     int temp;
     if(first == NULL){
        return;
     }
     for(i=first;i->link!=NULL;i=i->link){
        for(j=i->link;j!=NULL;j=j->link){
            if(i->info > j->info){
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
     }

}