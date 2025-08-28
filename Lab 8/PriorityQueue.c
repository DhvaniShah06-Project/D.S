#include "stdio.h"

int n=5;
int f=-1;
int r = -1;

struct element{
    int data;
    int priority;
};
struct element pq[5];
void enqueue(int , int);
void dequeue();
void display();

int main()
{
    int choice,value,priority;
    while (1)
    {
        printf("1 To Enqueue\n2 To Dequeue\n3 To Display\n4 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Number : ");
            scanf("%d", &value);
            printf("Enter Priority :");
            scanf("%d",&priority);
            enqueue(value,priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting");
            return 0;

        default:
            printf("Enter Valid Choice\n");
            break;
        }
    }

    return 0;
}

void enqueue(int y,int x)
{
    if (r >= n-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    r++;
    pq[r].data = y;
    pq[r].priority = x;
    if (f == -1)
    {
        f = 0;
    }
}

void dequeue()
{
    int i;
    if(f==-1)
    {
        return  ;
    }
    if(f==r)
    {
        f = r = -1;
        return ;
    }
    int high_index = f;
    for(i=f+1; i <=r;i++)
    {
        if( pq[i].priority > pq[high_index].priority)
     
            high_index = i;
        
       
    }
    printf("Dequeued Element : %d | %d\n",pq[high_index].data,pq[high_index].priority);
    for(i=high_index ; i<=r ; i++)
    {
        pq[i] = pq[i+1];

    }
    r--;
    
}

void display()
{
    printf("-----Displaying Queue-----\n");
    for (int i = f; i <= r; i++)
    {
        printf("%d|%d-->", pq[i].data,pq[i].priority);
    }
    printf("END\n");
}
// int dequeue()
// {
//     if (f == -1)
//     {
//         printf("Queue Underflow\n");

//         return 0;
//     }
//     int y = q[f];
//     if (f == r)
//     {
//         f = r = -1;
//     }
//     else
//     {
//         f++;
//     }
//     return y;
// }