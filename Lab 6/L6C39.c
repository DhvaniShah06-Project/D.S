#include"stdio.h"
#include"string.h"
int start[100];
int end[100];
int top = -1,t;
void push(int s , int e);
int pop();
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
    t = top;
  start[top]=s;
  end[top]=e;

}

int pop()
{
     if (top < 0) {
        printf("Stack underflow\n");
        return 0;
    }
  
  return start[--top];
}

void display()
{
    printf("Intervals\n");
    for(int i=0;i<=t;i++)
    {
        printf("{%d %d} ",start[i],end[i]);
    }
}

void merge(int n)
{
    
    int arrs[10],arre[10],k=0;
    for (int j = 0; j < t; j++) {
        if (end[j] > start[j+1]) {
            printf("end %d start j+1 %d\n",end[j],start[j+1]);
            //eg 1,3   2,4 3>2 so swap 3 and 4 so 1,4 2,3 and then pop 2,3
            //swap endj+1 and end j
            int temp;
            if(end[j]<end[j+1]){
            temp = end[j] ;
            end[j] = end[j+1];
            end[j+1] = temp;
            printf("Current %d %d\n",start[j],end[j]);
            printf("to pop : %d %d\n",start[j+1],end[j+1]);
            arrs[k++] = start[j+1];
            arre[k++] = end[j+1];
            
            top = j+2;
            printf("Top %d\n",top);
            printf("array %d %d\n",arrs[k-1],arre[k-1]);
            }
            else if(end[j]>end[j+1])
            {
                int s;
                s = start[j];
                start[j] = start[j+1];
                start[j+1] = s;
                 printf("Current %d %d\n",start[j],end[j]);
            printf("to pop : %d %d\n",start[j+1],end[j+1]);
            arrs[k++] = start[j+1];
            arre[k++] = end[j+1];
            printf("array %d %d\n",arrs[k-1],arre[k-1]);
            top = j+2;
            printf("Top %d\n",top);
            }

            // int tempS = start[j];
            // int tempE = end[j];
            // start[j] = start[j + 1];
            // end[j] = end[j + 1];
            // start[j + 1] = tempS;
            // end[j + 1] = tempE;
           int x= pop();
           printf("Start Pop %d\n",x);
        }
       
       
    }


// Step 2: Clear stack and push first interval
// top = -1;
// push(start[0], end[0]);


    
    
    display();
}