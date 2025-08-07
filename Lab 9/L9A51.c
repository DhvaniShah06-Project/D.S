#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size, i, sum;
    printf("Enter Size Of Array : ");
    scanf("%d", &size);
    int *as = (int *)calloc(size, sizeof(int));

    for (i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", as + i);
    }
    for (i = 0; i < size; i++)
    {
        sum = sum + *(as + i);
    }
    printf("Sum : %d", sum);
    free(as);
    return 0;
}