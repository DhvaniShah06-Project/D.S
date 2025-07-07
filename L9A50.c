# include<stdio.h>
# include<stdlib.h>
int main(){
    int size,i;
    printf("Enter Size Of Array : ");
    scanf("%d",&size);
    int *as = (int*)calloc(size,sizeof(int));
    
    
    for(i=0;i<size;i++){
        printf("Enter Array Element : ");
        scanf("%d",as+i);
    }
    for(i=0;i<size;i++){
        printf("%d, ",*(as+i));
    }
    free(as);
    return 0;
}