#include<stdio.h>

int main(){
    int Row,i,j,k,sum=1;
    printf("Enter Row : ");
    scanf("%d",&Row);

    for(i=0;i<Row;i++){
        for(k=1;k<=Row-i;k++){
            printf("  ");
        }
        sum=1;
        for(j=0;j<=i;j++){
        
        printf("  %d ",sum);
           sum=sum * (i-j)/(j+1);
        }
       
        
    
        
        printf("\n");
    }
    
        return 0;
    }