#include <stdio.h>
#include "string.h"
void push(char);
int check();
int top = -1;
char s[100];
void push(char);
int isMatching(char o, char c);
int isValid(char input[]);
char pop();
int main()
{
    int n, j = 0;
    printf("Enter Number Of Parenthesis : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++, j++)
    {
        char input[100];
        printf("Enter String : ");
        scanf("%s", input);
        int ans = isValid(input);
        if (ans == 1)
        {
            printf("Valid Answer\n");
        }
        else
        {

            printf("Invalid\n");
        }
    }

    return 0;
}
void push(char b)
{

    top++;
    s[top] = b;
}

char pop()
{
    top--;
    return s[top + 1];
}
int isMatching(char o, char c)
{

    return (o == '(' && c == ')' || o == '{' && c == '}' || o == '[' && c == ']');
}

int isValid(char input[])
{
    top = -1;
    int i;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            push(input[i]);
        }
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            if (top == -1)
                return 0;
            char x = pop();
            if (!isMatching(x, input[i]))
            {
                return 0;
            }
        }
    }
    return (top == -1);
}