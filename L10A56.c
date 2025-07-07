#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link; // self defined structurial
};
struct node *first = NULL;
void main(){
    int x;
    scanf("%d",&x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    printf("%d",newNode->info);
    
}