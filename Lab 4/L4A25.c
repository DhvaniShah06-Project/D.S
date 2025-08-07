#include<stdio.h>
int main(){
    int i,loc,size;
  printf("Enter Size : ");
    scanf("%d",&size);
     int a[20];
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
        }
        printf("Enter location : ");
        scanf("%d",&loc);
        for(i=loc;i<size;i++){
            a[i]=a[i+1];
        }
        size--;
        for(i=0;i<size;i++){
            printf("%d ",a[i]);
        }

    return 0;

}