#include<stdio.h>

int main(){
    int size,i=0;
    printf("Enter Size : ");
    scanf("%d",&size);
    int a[size];
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",&a[i]);
        }
    
    printf("Array Elements\n");
    for(int j=0;j<size;j++){
        printf("%d ",a[j]);
    }
    
    
    return 0;
}