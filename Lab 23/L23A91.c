#include "stdio.h"
void Insertion_sort(int[], int);
int main()
{
    int size;
    printf("Enter Size : ");
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", &a[i]);
    }
    Insertion_sort(a, size);
    return 0;
}

void Insertion_sort(int a[], int size)
{
    int i = 1;
    while (i < size)
    {
        int key = a[i] ;
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        i++;
    }
    printf("---Sorted Array---\n");
    for (int k = 0; k < size; k++)
    {
        printf("%d ", a[k]);
    }
}