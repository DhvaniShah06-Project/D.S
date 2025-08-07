#include<stdio.h>
#include<math.h>
void arm();
int main(){
   printf("Armstrong Numbers Between 1 to 1000 are : \n[");
   for(int i=1;i<=1000;i++){
    arm(i);
   }
   printf("]");
  
}
void arm(int i){
   int sum=0,rem;
   int temp = i;
   int digit=0;
   int k=i;
   while(k!=0){
    digit++;
    k=k/10;
   }
 while(i!=0){
    rem=i%10;
    sum=sum+pow(rem,digit);
     i=i/10;
  
 }
 if (sum==temp){
    printf("%d,",temp);
 }
 
}
/* temp=n;
    printf("Enter number of digits : ");
    scanf("%d",&digits);
   
    }*/