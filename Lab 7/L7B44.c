#include "stdio.h"
#include "string.h"
#include<ctype.h>
#include<math.h>
int top = -1;
char s[100];

void Eval_prefix(char prefix[]);
void push(int c);
int pop();
int main()
{
    char prefix[100];
    printf("Enter Prefix String : ");
    scanf("%s",prefix);
    Eval_prefix(prefix);
    int val = pop();
    printf("Answer : %d",val);
    
    return 0;
}

void push(int c)
{
    if(top>=99)
    {
        printf("Stack Overflow");
        return;
    }
    else{
        s[++top]=c;
    }
}

int pop()
{
    
    return s[top--];
}

void Eval_prefix(char prefix[])
{
   
    int i;
   for(i=strlen(prefix)-1;i>=0;i--)
    {
        
        if(isdigit(prefix[i])){
           push(prefix[i] - '0');
        }
        else{
            int operand1 = pop();
            printf("Op 1 : %d\n",operand1);
            int operand2 = pop();
            printf("Op 2 : %d",operand2);
            switch(prefix[i])
            {
                case'+':
                push(operand1 + operand2);
                break;
                case'-':
                push(operand1 - operand2);
                break;
                case'*':
                push(operand1*operand2);
                break;
                case'/':
                push(operand1/operand2);
                break;
                case'%':
                printf("Push : %d",operand1%operand2);
                push(operand1%operand2);
                break;
                 case '^':
                push(pow(operand1, operand2));
                break;
            }
        }
    }
}