#include <stdio.h>
int main()
{
    int num, size, i;
    int a[20];
    printf("Enter Size : ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", &a[i]);
    }
    printf("Enter Number : ");
    scanf("%d", &num);
    int loc = 0;
    for (i = 0; i < size; i++)
    {
        if (num < a[i])
        {
            loc = i;
            break;
        }
    }

        for(i=size-1;i>=loc;i--)
        {
        a[i+1]=a[i];
        if(i==loc){
            a[loc]=num;
            size++;
            break;
          
        
        }
    }
    
    for (i = 0; i < size; i++)
        
    {
        printf("%d ", a[i]);
    }

    return 0;
}