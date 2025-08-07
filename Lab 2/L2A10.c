#include<stdio.h>
#include<math.h>
int main(){
    int n,temp,rem;
    printf("Enter Number : ");
    scanf("%d",&n);
    temp = n;
    int sum=0;
    while(n!=0){
     rem=n%10;
    sum=(sum*10)+rem;
    n=n/10;
     
    }
    printf("Original Number : %d",temp);
    printf("\nReverse Number : %d",sum);
    
    return 0;
}