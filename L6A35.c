#include <stdio.h>
#include <string.h>
void push(char);
char pop();
void check();
void display();
int top = -1;
char s[50];

int main()
{
    int choice;
    char next, ans;
    while (1)
    {
        printf("1 To Check Grammar\n2 to display\n3 To exit\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            check();
            break;
        case 2:
        display();
        break;
        case 3:
            printf("---Exiting---");
            return 0;
        }
    }

    return 0;
}

void check()
{
    char  x;
    int i = 0;
    char original[50];
    printf("Enter To Check : ");
    scanf("%s", original);
    top++;
    s[top] = 'c';
    char next;
    next = original[i];
    // i++;
    while (next != 'c')
    {
        if (next == '\0')
        {
            printf("Invalid Sting\n");
        }
        else
        {
            push(next);
            i++;
            next = original[i];
        }
    }

    i++;
    while (s[top] != 'c')
    {
        next = original[i];
        i++;
        x = pop();
        printf("Pop : %c\n",x);
        if (next != x && next!='\0')
        {
            printf("Invalid String\n");
            return;
        }
    }
     next = original[i];

    if (next == '\0')
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
}

void push(char next)
{
    top++;
    s[top] = next;
    printf("Stack : %c\n",s[top]);
}
char pop()
{
    top--;
    printf("Pop Element : %c\n",s[top+1]);
    return s[top + 1];
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
        printf("%c\n", s[i]);
    }
}