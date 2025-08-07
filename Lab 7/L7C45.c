#include "stdio.h"
#include<string.h>

int top = -1;
int s[100];

void push(int );
int pop();
void check(int a[], int);
void checkAsc(int [] , int);
int main()
{
    
    int n,sa,sb;
    // printf("Enter n : ");
    // scanf("%d",&n);
    printf("Enter Size A : ");
    scanf("%d",&sa);
    // printf("Enter Size B : ");
    // scanf("%d",&sb);
    int a[sa],b[sb];
    for(int i=0;i<sa;i++){
        printf("Enter array A : ");
        scanf("%d",&a[i]);
    }
        // for(int i=0;i<sb;i++){
        // printf("Enter array B : ");
        // scanf("%d",&b[i]);
        // }
    
        check(a, sa);
    
    
    
    return 0;
}

void check(int a[], int sa)
{
    int ans[sa];
    int i=0,j=0;
    for(;i<sa;i++)
    {
        if(top!=-1 && a[i] > s[top]){
            int x = pop();
            printf("Pop : %d\n",x);
            ans[j++]=x;
        }
        push(a[i]);
        // printf("Answer : %d\n",ans[j-1]);
    }
    if(top!=-1){
        while(top!=-1){
            ans[j++] = pop();
        }
    }
    for(int k=0;k<sa;k++){
    printf("Answer : %d\n",ans[k]);
    }
    checkAsc(ans, sa);
}

void checkAsc(int ans[] , int sa)
{
    int flag = 0;
    printf("Gone\n");
    for(int i=0;i<sa;i++)
    {
        for(int j=i+1;j<sa-1;j++){
            if(ans[i]>ans[j]){
                flag = 1;
                break;
            }
        }
    }
    if(flag==0){
        printf("Yes");
    }
    else{
        printf("No");
    }

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