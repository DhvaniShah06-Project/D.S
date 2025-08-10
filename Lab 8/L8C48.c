#include <stdio.h>
int f = -1;
int r = -1;
int n = 5;
int q[5];

void insertFirst(int);
void insertEnd(int);
int delFirst();
int delEnd();
void display();

int main()
{
    int choice, val, ans;
    while (1)
    {
        printf("1 To Insert First\n2 To Insert End\n3 To Delete from First\n4 To Delete From Last\n5 To Display\n6 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Number : ");
            scanf("%d", &val);
            insertFirst(val);
            break;
        case 2:
            printf("Enter Number : ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            ans = delFirst();
            printf("Delete First : %d\n", ans);
            break;
        case 4:
            ans = delEnd();
            printf("Delete Last : %d\n", ans);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("---Exiting---");
            return 0;
        default:
            printf("Enter Valid Choice\n");
            break;
        }
    }
}

void insertFirst(int val)
{
    if (f == -0)
    {
        printf("Front OverFlow\n");
        return;
    }
    if (f == -1)

        f = r = 0;

    else
        f--;
    q[f] = val;
}

void insertEnd(int val)
{
    if (r >= n - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    q[++r] = val;
    if (f = -1)
    {
        f = 0;
    }
}

int delFirst()
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

int delEnd()
{
    if (r == -1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    int y = q[r];
    if (f == r)
    {
        r = f = -1;
    }
    else
    {
        r--;
    }
    return y;
}

void display()
{
    if(f==-1)
    {
        printf("Queue Empty\n");
        return;
    }
    int i;
    for (i = f; i <= r; i++)
    {
        printf("%d-->", q[i]);
    }
    printf("NULL\n");
}