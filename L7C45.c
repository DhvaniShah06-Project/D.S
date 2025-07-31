#include "stdio.h"
#include<string.h>

int top = -1;
int s[100];

void push(int );
int pop();

int main()
{
    
    
    
    
    
    return 0;
}

void push(int a)
{
    s[++top] = a;
}

int pop()
{
    top--;
    return s[top+1];
}