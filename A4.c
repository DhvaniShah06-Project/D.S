#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter Numbers : ");
    scanf("%d %d %d",&a,&b,&c);
   (a>b)?((a>c)?(printf("%d is largest",a)):printf("%d is largest",c)):((b>c)?(printf("%d is Largest",b)):printf("%d is Largest",c));
    
    return 0;
}