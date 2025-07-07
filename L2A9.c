#include<stdio.h>
int main(){
    int base,power;
    int ans=1;
    printf("Enter Base Number : ");
    scanf("%d",&base);
    printf("Enter Power : ");
    scanf("%d",&power);
    for(int i=1;i<=power;i++){
        ans=ans*base;
    }
    printf("%d^%d = %d",base,power,ans);
       
    return 0;
}