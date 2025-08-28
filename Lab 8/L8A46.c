#include "stdio.h"
int f = -1;
int r = -1;
int n = 5;
int q[5];

void enqueue(int);
int dequeue();
void display();



int main()
{
    int choice, value,ans;
    while (1)
    {
        printf("1 To Enqueue\n2 To Dequeue\n3 To Display\n4 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Number : ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            ans = dequeue();
            printf("Deleted Element : %d\n", ans);
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

void enqueue(int y)
{
    if (r >= n-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    q[++r] = y;
    if (f = -1)
    {
        f = 0;
    }
}

int dequeue()
{
    if (f == -1)
    {
        printf("Queue Underflow\n");

        return 0;
    }
    int y = q[f];
    if (f == r)
    {
        f = r = -1;
    }
    else
    {
        f++;
    }
    return y;
}

void display()
{
    printf("-----Displaying Queue-----\n");
    for (int i = f; i <= r; i++)
    {
        printf("%d-->", q[i]);
    }
    printf("NULL\n");
}