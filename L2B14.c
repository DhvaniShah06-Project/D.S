#include<stdio.h>
int main(){
    int n,i,j,sum=0;
    printf("Enter Number : ");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        for(j=1;j<=i;j++){
            sum = sum+j;
        }
    }
    printf("%d",sum);
return 0;
}