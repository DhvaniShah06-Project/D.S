#include "stdio.h"
#include "stdlib.h"
int top = -1;
int s[5];
void push();
int pop();
int peek();
void display();
void change();
int main()
{
    int choice, ans, a;
    while (1)
    {
        printf("1 To Push\n2 To peek(return i th element from top)\n3 To Pop(remove top most)\n4 to change i th element from top\n5 To Display\n6 To exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            ans = peek();
            printf("Returned Element : %d\n", ans);
            break;
        case 3:
            a = pop();
            // printf("Top Most Pop : %d\n", a);
            break;
        case 4:
            change();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("---Exiting---");
            return 0;
        }
    }
    return 0;
}

void push()
{
    int x;
    if (top >= 4)
    {
        printf("overflow\n");
        return;
    }
    top++;
    printf("Enter Value : ");
    scanf("%d", &x);
    s[top] = x;
}

int peek()
{
    int i;
    printf("Enter ith Element from top ");
    scanf("%d", &i);
    if (top - i < 0)
    {
        printf("Empty Stack\n");
        return 0;
    }
    return s[top - i];
}
void display()
{
    if (top <= 0)
    {
        printf("Empty Stack\n");
        return;
    }
    int i;
    printf("---Displaying Stack ---\n");
    for (i = top ; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}
void change()
{
    int i, x;
    printf("Enter ith Element from top ");
    scanf("%d", &i);
    if (top - i < 0)
    {
        printf("Empty Stack\n");
        return;
    }
    printf("Original Value : %d\n", s[top - i]);
    printf("Enter Value To be changed : ");
    scanf("%d", &x);
    s[top - i] = x;
    printf("Changed Value : %d\n", s[top - i]);
}

int pop()
{

    if (top <= 0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    top--;
        // printf("Popped Element: %d\n", s[top+1]);
    return s[top+1];
}
