#include "stdio.h"
void Bubble_sort(int[] , int);
int main()
{
     int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int a[size];
       for(int i=0;i<size;i++)
    {
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
    }
    Bubble_sort(a,size);
    return 0;
}

void Bubble_sort(int a[] , int size){
    int last = size-1;
    int i=0,exchange;
    for(;i<=size-2;i++)
    {
        exchange = 0;
        for(int j=0;j<=last-1;j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                exchange++;
            }
        }
        if(exchange==0)
        {
            break;
        }
        else{
            last-=1;
        }
    }
      printf("---Sorted Array---\n");
    for(int k = 0 ;k<size;k++)
    {
        printf("%d ",a[k]);
    }
}