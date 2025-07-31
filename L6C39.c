#include"stdio.h"
#include"string.h"
int start[100];
int end[100];
int top = -1;
void push(int s , int e);
void pop();
void display();
void merge(int);

int main()
{
    int n,a,b;
    printf("Enter n : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter Start And End Point : ");
        scanf("%d %d",&a,&b);
        push(a,b);
    }
    merge(n);
}

void push(int s,int e)
{
    if(top>=99)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
  start[top]=s;
  end[top]=e;
}

void pop()
{
     if (top < 0) {
        printf("Stack underflow\n");
        return;
    }
  top--;
}

void display()
{
    printf("Intervals\n");
    for(int i=0;i<=top;i++)
    {
        printf("{%d %d} ",start[i],end[i]);
    }
}

void merge(int n)
{
    // Step 1: Sort intervals by start time
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (start[j] > start[j + 1]) {
            int tempS = start[j];
            int tempE = end[j];
            start[j] = start[j + 1];
            end[j] = end[j + 1];
            start[j + 1] = tempS;
            end[j + 1] = tempE;
        }
    }
}

// Step 2: Clear stack and push first interval
top = -1;
push(start[0], end[0]);

// Step 3: Traverse and merge using stack
for (int i = 1; i < n; i++) {
    if (start[i] <= end[top]) {
        // Merge
        if (end[i] > end[top])
            end[top] = end[i];
    } else {
        push(start[i], end[i]);
    }
}
    
    
    display();
}