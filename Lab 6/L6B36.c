#include<stdio.h>
#include<string.h>
void push(char);
int top = -1;
char s[50];
int main()
{

    char input[50];
    printf("Enter String : ");
    scanf("%s",input);
    int len = strlen(input);

    int i=0,cb=0;
    for(;i<=len-1;i++)
    {
        if(input[i]=='a')
        {
            push('a');
        }
        else if(input[i]=='b')
        {
            cb++;
        }
    }
    printf("Count b : %d\n",cb);
    printf("Top : %d\n",top);
    if(cb == top+1)
    {
        printf("Valid");
    }
    else{
        printf("Invalid");
    }

    return 0;
}


void push(char next)
{
    top++;
    s[top] = next;
    printf("Stack : %c\n",s[top]);
}
