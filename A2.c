#include<stdio.h>
int main(){
    int a;
    printf("Enter Number : ");
    scanf("%d",&a);
    if(a%2==0){
        printf("%d is Even",a);
    }
    else{
        printf("%d is odd",a);
    }
    return 0;
}