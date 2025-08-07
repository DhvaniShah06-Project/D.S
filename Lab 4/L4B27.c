#include <stdio.h>
int main()
{
    int size, i, num;
    printf("Enter Size : ");
    scanf("%d", &size);
    int a[20];
    for (i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", &a[i]);
    }
    printf("Enter Number To delete : ");
    scanf("%d", &num);
    for (i = 0; i < size; i++)
    {
        if (num == a[i])
        {
            for (; i < size; i++)
            {
                a[i] = a[i + 1];
            }
        }
    }
    size--;
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}