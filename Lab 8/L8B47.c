#include <stdio.h>
int f = -1;
int r = -1;
int n = 5;
int q[5];

void enqueue(int);
int dequeue();
void display();

int main()
{
    int choice, val, ans;
    while (1)
    {
        printf("1 To Enqueue\n2 To Dequeue\n3 To Display\n4 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Number : ");
            scanf("%d", &val);
            enqueue(val);
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
    if (r == n - 1)
    {
        r = 0;
    }
    else
    {
        r = (r + 1) % n;
    }
    if (f == r)
    {
        printf("Queue Overflow\n");
        return;
    }
    q[r] = y;
    if (f == -1)
    {
        f = 0;
    }

    return;
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
        f = (f + 1) % n;
    }
    return y;
}

void display()
{
    if (f == -1)
    {
        printf("Queue Is Empty\n");
        return;
    }
    int i = f;
    printf("-----Displaying Circular Queue-----\n");
    do
    {
        printf("%d --> ", q[i]);
        i = (i + 1) % n;
    } while (i != (r + 1) % n);

    printf("NULL\n");
}