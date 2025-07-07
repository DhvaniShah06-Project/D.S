#include <stdio.h>
int main()
{
    int size, i, j = 1, dup = 0, k;
    int a[20], b[20];
    printf("Enter Size : ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", &a[i]);
    }
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size;)
        {
            if (a[i] == a[j])
            {
                b[dup] = a[j];
                dup++;
               
                for (k = j; k < size - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                 size--;
            }
            else
            {
                j++;
            }
        }
    }
    printf("Array Without Duplicate Numbers : \n");
    for (i = 0; i < size; i++)
    {
        if (size == 0)
        {
            printf("%d ", a[i]);
        }
        else
        {
            printf("%d ", a[i]);
        }
    }
     if (dup > 0) {
        printf("\nDuplicate Numbers In Array:\n");
        for (i = 0; i < dup; i++) {
            printf("%d ", b[i]);
        }
    } else {
        printf("\nNo duplicate elements found.");
    }


    return 0;
}