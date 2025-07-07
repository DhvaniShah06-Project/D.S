#include<stdio.h>

int main(){
    int size,i=0,sum=0,d,flag=0;
    printf("Enter Size : ");
    scanf("%d",&size);
     int a[size];
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
        }
        d=a[0];
        for(i=0;i<=size;i++){
            if(d==a[i+1]){
                flag=1;
            }
            
        }
        if(flag==1){
            printf("Duplicate Exists");
        }
        else{
            printf("Duplicate not");
        }
        return 0;
    }