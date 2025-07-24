# include "stdio.h"
#include "string.h"

int top = -1;
char s[100];
void push (char);
void pop(char);
void display();
int main()
{
    int i=0;
    char input[100];
    printf("Enter String : ");
    scanf("%s",input);
    int len = strlen(input);
    for(;i<=len-1;i++){
        if(input[i]=='*'){
            pop(input[i-1]);
        }
        else{
            push(input[i]);
        }
    }
    
     display();
    return 0;
//lee**tcod*e
}

void display(){
    if(top==-1)
    {
        printf("Empty");
    }
 for (int i = 0 ; i <=top; i++)
    {
        printf("%c", s[i]);
    }
}

void push(char a)
{
    
    top++;
    s[top] = a;
}

void pop(char b)
{
    top--;
    
}