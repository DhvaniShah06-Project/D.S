#include <stdio.h>
int main()
{
    int i=0,j;
    for(;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==0||i==3)
            {
                printf("* ");
            }
           else if(j==0 || j==3)
            {
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}