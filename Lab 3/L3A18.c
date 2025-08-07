#include<stdio.h>

int main(){
    int size,i=0,sum=0,n;
    printf("Enter Size : ");
    scanf("%d",&size);
     int a[size];
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
        }
        printf("Enter n : ");
        scanf("%d",&n);
         for(i=0;i<n;i++){
    sum=sum+a[i];
    
         }
      float ans = (float)sum/n;
         printf("Average : %f",ans);
    return 0;
}
