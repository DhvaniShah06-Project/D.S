#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *insEnd(struct node *);
void playNext(struct node *);
void playPrev(struct node *);
// delete();
void display(struct node *);
struct node
{
    char Songs[150];
    struct node *lptr;
    struct node *rptr;
};
struct node *curr = NULL;
struct node *first = NULL;

int main()
{
    int choice;
    while (1)
    {
        printf("1 To Insert Songs At End\n2 To Display\n3 To Play Previous Songs\n4 To Play Next Song\n5 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insEnd(first);
            break;
        case 2:
            display(first);
            break;
        case 3:
            playPrev(curr);
            break;
        case 4:
            playNext(curr);
            break;
        case 5:
            printf("---Exiting---");
            return 0;
        }
    }
}
struct node *insEnd(struct node *first)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    char s[150];
    printf("Enter Song : ");
    scanf("%s", s);
    strcpy(newNode->Songs, s);
    if (first == NULL)
    {
        newNode->lptr = newNode;
        newNode->rptr = newNode;
        first = newNode;
        curr = first;
        return first;
    }
    else
    {
        struct node *last = first->lptr;
        newNode->lptr = last;
        newNode->rptr = first;
        last->rptr = newNode;
        first->lptr = newNode;
    }
    return first;
}
void display(struct node *first)
{
    struct node *temp = first;
    if (temp == NULL)
    {
        printf("Empty Song List\n");
        return;
    }
    printf("\n---Playlist---\n");
    do
    {
        if (curr == temp){

        printf("--> %s (Current)  <| || |>", curr->Songs);
        }

        else{
            printf("   %s", temp->Songs);
        }
        printf("\n");

        temp = temp->rptr;

    } while (temp != first);
}
void playNext(struct node *first)
{
     if (curr == NULL) {
        printf("No songs in the playlist.\n");
        return;
    }

    curr = curr->rptr;
            // printf("--> %s (Current)  <| || |>\n", curr->Songs);
    display(first);
}
void playPrev(struct node *)
{
     if (curr == NULL) {
        printf("No songs in the playlist.\n");
        return;
    }

    curr = curr->lptr;
            // printf("--> %s (Current)  <| || |>\n", curr->Songs);

    display(first);
}