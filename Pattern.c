#include<stdio.h>
int main(){
int i,j;
int m=1;
for(i=0;i<=5;i++){
    for(int j=1;j<=i;j++){
        // printf("* ");
        printf("%d ",m);
        m++;
    }
    printf("\n");
}



    return 0;

}