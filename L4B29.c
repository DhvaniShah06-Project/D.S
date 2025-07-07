#include <stdio.h>
int main()
{
    int sizea, sizeb, i, j;
    printf("Enter Array 1 Size : ");
    scanf("%d", &sizea);
    printf("Enter Array 2 size : ");
    scanf("%d", &sizeb);
    int a[sizea], b[sizeb], c[sizea + sizeb];
    printf("Array 1 : \n");
    for (i = 0; i < sizea; i++)
    {
        printf("Enter Array  Element : ");
        scanf("%d", &a[i]);
    }
    printf("Array 2 : \n");
    for (i = 0; i < sizeb; i++)
    {
        printf("Enter Array  Element : ");
        scanf("%d", &b[i]);
    }

    for (i = 0; i < sizea; i++)
    {
        c[i] = a[i];
    }
    for (j = sizea, i = 0; j < sizea + sizeb - 1, i < sizeb; j++, i++)
    {
        c[j] = b[i];
    }
    printf("Merged Array : ");
    for (i = 0; i < sizea + sizeb; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}