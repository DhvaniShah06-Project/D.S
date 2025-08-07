#include<stdio.h>

int main(){
    int n,flag;
    printf("Enter Number : ");
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(n%i==0){
            flag=0;
            break;
        }
        else{
            flag=1;
        }
    }
    if(flag==0){
        printf("%d is Not Prime ",n);
    }
    else{
        printf("%d is Prime",n);
    }
    
    
    
    return 0;
}