#include"stdio.h"
#include"string.h"
int s[100];
int top = -1;
void push(char);
void pop();

int main()
{

}

void push(char x)
{
    s[++top] = x;
}

void pop()
{
    top--;
    return s[top+1];
}