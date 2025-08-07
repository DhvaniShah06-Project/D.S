#include "stdio.h"
#include "string.h"
#include <ctype.h>
#include <math.h>
int top = -1;
char s[100];

void Eval_postfix(char postfix[]);
void push(int c);
int pop();
int main()
{
    char postfix[100];
    printf("Enter String : ");
    scanf("%s", postfix);
    Eval_postfix(postfix);
    printf("Answer : %d", pop());

    return 0;
}

void push(int c)
{
    if (top >= 99)
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        s[++top] = c;
    }
}

int pop()
{
    top--;
    return s[top + 1];
}

void Eval_postfix(char postfix[])
{

    int i = 0;
    for (i = 0; i < strlen(postfix); i++)
    {

        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();
            switch (postfix[i])
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '^':
                push(pow(operand1, operand2));
            }
        }
    }
}