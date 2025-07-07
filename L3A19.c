#include<stdio.h>

int main(){
    int size,i,min,max,imin=0,imax=0;
       printf("Enter Size : ");
    scanf("%d",&size);
   int a[size];
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
        }
        min = a[0];
        max=a[0];
        for(i=0;i<size;i++){
           if(min>a[i]){
           min=a[i];
           imin = i;
           }
           if(max<a[i]){
            max=a[i];
            imax = i;
           }
        }
 
        printf(" Minimum Value and Position : %d %d\n",min,imin);
            printf("Maximum value and Position :  %d  %d",max,imax);
    return 0;
}