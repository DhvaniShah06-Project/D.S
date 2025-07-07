#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, i, max;
    printf("Enter Size Of Array : ");
    scanf("%d", &size);
    int *as = (int *)calloc(size, sizeof(int));

    for (i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", as + i);
    }
    max = *(as + 0);
    for (i = 0; i < size; i++)
    {
        if (max < *(as + i))
        {
            max = *(as + i);
        }
    }
    printf("Maximum : %d", max);
    free(as);
    return 0;
}