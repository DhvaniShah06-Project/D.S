#include<stdio.h>

int main(){
    int size,i,rep,num,index;
    printf("Enter Size : ");
    scanf("%d",&size);
     int a[size];
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
        }
        printf("Enter number to be replaced : ");
        scanf("%d",&rep);
        printf("Enter What to replace With :\n ");
        scanf("%d",&num);
        for(i=0;i<size;i++){
            if(rep==a[i]){
                a[i]=num;
                index=i;

            }
        }
        printf("New Array : \n");
        for(i=0;i<size;i++){
            printf("%d ",a[i]);
        }
        printf("Altered Number's Index : %d",index);

        return 0;
    }