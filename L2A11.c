#include<stdio.h>
int main(){
     int n;
    printf("Enter Number : ");
    scanf("%d",&n);
    printf("Factors Are : \n");
    for(int i=1;i<=n;i++){
        if(n%i==0){
            printf("%d ",i);
        }
    }
    return 0;
}