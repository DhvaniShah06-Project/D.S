#include<stdio.h>

int main(){
    int size,i,loc,val,temp;
    printf("Enter Size : ");
    scanf("%d",&size);
     int a[20];
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
        }
        printf("Enter Number To be Inserted and location : ");
        scanf("%d %d",&val,&loc);
        for(i=size;i>=0;i--){
        a[i]=a[i-1];
        if(i==loc){
            a[loc]=val;
            size++;
          
        }
        }
        
        
        printf("Sorted Array after alteration : \n");
        for(i=0;i<size;i++){
            printf("%d ",a[i]);
        }

        return 0;
    }