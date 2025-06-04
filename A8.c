#include<stdio.h>

int fact();
int main(){
    int n,ans;
    printf("Enter Number : ");
    scanf("%d",&n);
    
     ans= fact(n);
    
    printf("Factorial : %d",ans);
    
    return 0;
}
int fact(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
      
    }
}