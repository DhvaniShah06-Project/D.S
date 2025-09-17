#include <stdio.h>

int Sequential_Search(int[], int, int);

int main()
{
    int size, a, find;
    printf("Enter Size : ");
    scanf("%d", &size);
    int b[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", &b[i]);
    }
    printf("Enter Element to be searched : ");
    scanf("%d", &find);
    a = Sequential_Search(b, find, size);
    if (a == -1)
    {
        printf("%d Not Found", find);
    }
    else
    {
        printf("%d Found At : %d", find, a);
    }
}

int Sequential_Search(int a[], int key, int size)
{
    int i = 0;
    for (; i < size; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}
