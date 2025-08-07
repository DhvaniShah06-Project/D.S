# include<stdio.h>
# include<stdlib.h>

int main(){
    

    int *ip = (int*)malloc(sizeof(int));
    char *cp = (char*)malloc(sizeof(char));
    float *fp = (float*)malloc(sizeof(float));
    if(ip && fp && cp){
    *ip = 5;
    *cp = 'd';
    *fp = 5.205;
    printf("Integer : %d\n",*ip);
    printf("Character : %c\n",*cp);
    printf("Float : %f\n",*fp);
    }
    
    free(ip);
    free(cp);
    free(fp);

    
    
    
    return 0;
}
