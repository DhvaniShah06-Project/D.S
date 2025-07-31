#include <stdio.h>
#include <string.h>

char s[100];
int top = -1;

void rev_pol(char infix[]);
int input_precedence(char);
int stack_precedence(char);
int r(char c);
void push(char c);
char pop();

int main()
{
    char infix[100];
    printf("Enter  Infix : ");
    scanf("%s",infix);
    strcat(infix,")");
    push('(');
    rev_pol(infix);
    
    return 0;
}
void push(char a)
{
    if (top > 99)
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        s[++top] = a;
    }
}

char pop()
{
    top--;
    return s[top + 1];
}

int stack_precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '*' || c == '/' || c == '%')
    {
        return 4;
    }
    else if (c == '^')
    {
        return 5;
    }
    else if (c == '(')
    {
        return 0;
    }
    else
    {
        return 8;
    }
}

int input_precedence(char c)
{
       if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/' || c == '%')
    {
        return 3;
    }
    else if (c == '^')
    {
        return 6;
    }
    else if (c == '(')
    {
        return 9;
    }
    else if(c==')')
    {
        return 0;
    }
    else
    {
        return 7;
    }
}

int r(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    {
        return -1;
    }
    else{
        return 1;
    }
}

void rev_pol(char infix[])
{
    int i=0,j=0,rank = 0;
    char polish[100];
    char next;
    while(i!=strlen(infix))
    {
        next = infix[i];
        if(top<0)
        {
            printf("Invalid top");
            return;
        }
        while(stack_precedence(s[top])>input_precedence(next)){
            char temp = pop();
            polish[j++] = temp;
            rank = rank + r(temp);
            if(rank<1)
            {
                printf("Invalid rank");
                return;
            }
        }
            if(stack_precedence(s[top])!=input_precedence(next))
            {
                push(next);
            }
            else{
               char temp = pop();
            }
            i++;
        
        
    }
    polish[j] = '\0';
    if(top !=-1|| rank !=1)
    {
        printf("Invalid end");
    }
    else 
    {
        printf("Polish String(PostFix) : %s",polish);
    }

    
}

