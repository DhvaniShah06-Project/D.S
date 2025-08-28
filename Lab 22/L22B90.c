#include "stdio.h"
void Selection_sort(int[] , int);
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
    Selection_sort(a,size);
    return 0;
}

void Selection_sort(int a[], int n)
{
    int i=0;
    for(;i<=n-2;i++){
        int min_index = i;
        for(int j=i+1;j<=n-1;j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
         if(min_index !=i){
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
         }

    }
    printf("---Sorted Array---\n");
    for(int k = 0 ;k<n;k++)
    {
        printf("%d ",a[k]);
    }

}