#include "stdio.h"
void mergeSort(int[],int,int);
void merge(int [],int,int,int);
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
    mergeSort(a,0,size-1);
    
    // Selection_sort(a, size);
    return 0;
}

void mergeSort(int a[],int low,int high){
    if(low<high){
       int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
 
void merge(int a[],int low,int mid,int high)
{
    int h,i,j,k;
    int b[high-low+1];
    h= low;
    i=0;
    j = mid+1;
    while(h<=mid && j<=high)
    {
        if(a[h] <= a[j]){
            b[i++] = a[h];
            h++;
        }
        else{
            b[i++] = a[j];
            j++;
        }
        
    }
    while(h<=mid)
    {
        b[i++] = a[h++];
    }
    while(j<=high)
    {
        b[i++] = a[j++];
    }
    printf("Sorted Array!\n");
    for(int k=low,i=0;k<=high;i++,k++){
        a[k] = b[i];
        printf("%d ",a[k]);
    }
}