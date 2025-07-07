#include<stdio.h>
int main(){
     int a,b,flag;
    printf("Enter Number : ");
    scanf("%d %d",&a,&b);
    printf("Prime Number Between Interval [%d,%d] are : \n",a,b);
    for(int i=a;i<=b;i++){
      for(int k=2;k<i;k++){
        if(i%k==0){
            flag=0;
            break;
        }
        else{
            flag=1;
        }
      }
      if(flag==1){
        printf("%d ",i);
      }
    }
    return 0;
        }