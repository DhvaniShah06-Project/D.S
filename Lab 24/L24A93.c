#include "stdio.h"
// void Selection_sort(int[] , int);
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
    // Selection_sort(a, size);
    return 0;
}