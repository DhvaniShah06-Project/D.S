#include <stdio.h>

int main()
{
    int size, i = 0, s, e, v = 0, sum = 0;
    printf("Enter Size : ");
    scanf("%d", &size);
    int a[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", &a[i]);
    }
    printf("Enter start and End Index : ");
    scanf("%d %d", &s, &e);
    for (i = s; i <= e; i++)
    {
        sum = sum + a[i];
    }

    printf("Sum : %d", sum);
    return 0;
}