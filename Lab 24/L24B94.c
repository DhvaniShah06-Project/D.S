#include "stdio.h"
void quick_sort(int[], int, int);
void display(int[], int);
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
    quick_sort(a, 0, size - 1);
    display(a, size);
    return 0;
}

void quick_sort(int a[], int lb, int ub)
{
    int flag = 1;
    if (lb < ub)
    {
        int j = ub + 1;
        int i = lb;
        int key = a[lb];
        while (flag == 1)
        {
            i++;
            while (a[i] < key && i < ub)
            {
                i++;
            }

            j--;
            while (a[j] > key && j > lb)
            {
                j--;
            }

            if (i < j)
            {

                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else
            {
                flag = 0;
            }
        }

        int temp = a[lb];
        a[lb] = a[j];
        a[j] = temp;

        quick_sort(a, lb, j - 1);
        quick_sort(a, j + 1, ub);
    }
}

void display(int a[], int size)
{
    printf("---Array---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}