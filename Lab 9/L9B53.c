#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, i, j, min, temp;
    printf("Enter Size Of Array : ");
    scanf("%d", &size);
    int *as = (int *)malloc(sizeof(int));

    for (i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", as + i);
    }
    min = *as;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(as + j) > *(as + j + 1))
            {
                temp = *(as + j);
                *(as + j) = *(as + j + 1);
                *(as + j + 1) = temp;
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(as + i));
    }
    free(as);
    return 0;
}